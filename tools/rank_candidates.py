#!/usr/bin/env python3
r"""Rank unowned functions and repetitive implementation candidates by byte gain.

Examples (no build, compiler, binary, or cache writes):
    python tools\rank_candidates.py --start 0x400000 --end 0x476B00
    python tools\rank_candidates.py --input-root SNAPSHOT --json
    python tools\rank_candidates.py --report REPORT --asm-root ASM --research-index ADDRESS_INDEX --json

Inputs are ordered splat spans and an objdiff report. Function addresses in the
report are section-relative, NOT inferred from function/source filenames. Every
C span is reserved, including incomplete units and secondary functions within a
unit. Missing/stale inventory and C completion are reported separately. Bounds
are half-open; functions crossing them or ownership boundaries are not offered.

Gain means reported function size, excluding inter-function gaps (which are not
assumed to be padding). It is potential gain, not measured bytes/hour. Groups
are HEURISTIC candidates, never matches: only local branch labels and whitespace
are normalized. Registers, immediates, offsets, external targets, and relocation
expressions remain distinct. No instructions or retail bytes appear in output.
JSON contains all candidates; --limit only limits the human display.
"""
import argparse
from bisect import bisect_right
from collections import defaultdict
from dataclasses import dataclass
import hashlib
import json
from pathlib import Path
import re
import sys

import yaml

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
from configure import subsegments, unit_name  # noqa: E402

CODE_TYPES = {"asm", "hasm", "c"}
# The addressed instruction format is shared with tools/autodecomp/run.py.
INSN = re.compile(r"^\s*/\*\s+\S+\s+([0-9a-fA-F]{8})\s+[0-9a-fA-F]{8}\s+\*/\s*(.*?)\s*$")
LOCAL_LABEL = re.compile(r"^\s*(\.L[\w.$]+):")
LOCAL_REF = re.compile(r"(?<![\w.$])\.L[\w.$]+")


def number(value):
    """Accept JSON decimal strings and explicit hexadecimal CLI/YAML values."""
    if isinstance(value, bool):
        raise ValueError("boolean is not an address or size")
    if isinstance(value, int):
        return value
    if isinstance(value, str):
        return int(value, 16 if value.lower().startswith("0x") else 10)
    raise ValueError(f"expected an integer, got {value!r}")


def address(value):
    return f"0x{value:08X}"


@dataclass(frozen=True)
class Span:
    start: int
    end: int
    kind: str
    name: str


def config_spans(config):
    """Use the same main-segment/unit naming rules as configure.py."""
    segments = config["segments"]
    segment = segments[0]
    if segment["type"] != "code":
        raise ValueError("the first splat segment must be code")
    subs = subsegments(config)
    if len(segments) < 2:
        raise ValueError("splat needs a following segment/end marker")
    following = segments[1]
    end = number(following["start"] if isinstance(following, dict) else following[0])
    base = number(segment["vram"]) - number(segment["start"])
    starts = [number(s[0]) for s in subs] + [end]
    if not subs or starts[0] != number(segment["start"]):
        raise ValueError("subsegments must cover the start of the main segment")
    if any(a >= b for a, b in zip(starts, starts[1:])):
        raise ValueError("splat subsegments must be strictly ordered")
    spans = []
    for (offset, kind, name), start, stop in zip(subs, starts, starts[1:]):
        name = unit_name(kind, name, number(offset)) if kind == "c" else f"{kind}/{base + start:06X}"
        spans.append(Span(base + start, base + stop, kind, name))
    if len({s.name for s in spans}) != len(spans):
        raise ValueError("duplicate splat unit names")
    return spans


def union_size(intervals):
    total, last = 0, -1
    for start, end in sorted(intervals):
        if end > max(start, last):
            total += end - max(start, last)
        last = max(last, end)
    return total


def intersection_size(intervals, spans, start, end):
    intersections = []
    i = 0
    for a, b in sorted(intervals):
        a, b = max(a, start), min(b, end)
        while i < len(spans) and spans[i].end <= a:
            i += 1
        j = i
        while j < len(spans) and spans[j].start < b:
            low, high = max(a, spans[j].start), min(b, spans[j].end)
            if low < high:
                intersections.append((low, high))
            j += 1
    return union_size(intersections)


def complete_unit(unit):
    measures = unit.get("measures", {})
    total = number(measures.get("total_code", 0))
    return (unit.get("metadata", {}).get("complete") is True
            and total > 0 and number(measures.get("complete_code", 0)) == total)


def report_inventory(report, spans):
    """Locate units by configured ownership, not source-file existence."""
    named = {s.name: s for s in spans}
    functions, coverage, unmapped = [], [], []
    seen_units = set()
    for unit in report["units"]:
        name = unit["name"]
        if name in seen_units:
            raise ValueError(f"duplicate report unit {name}")
        seen_units.add(name)
        text = [s for s in unit.get("sections", []) if s["name"] == ".text"]
        if not text:
            if unit.get("functions"):
                raise ValueError(f"functions without .text in {name}")
            continue
        if len(text) != 1:
            raise ValueError(f"ambiguous .text sections in {name}")
        size = number(text[0].get("size", 0))
        if size == 0 and not unit.get("functions"):
            continue
        match = re.fullmatch(r"(?:asm|hasm)/([0-9a-fA-F]+)", name)
        if match:
            base = int(match[1], 16)
        elif name in named and named[name].kind == "c":
            base = named[name].start
        else:
            unmapped.append(name)
            continue
        if size <= 0:
            raise ValueError(f"invalid .text size in {name}")
        coverage.append((base, base + size))
        entries = sorted(unit.get("functions", []), key=lambda f: (number(f["address"]), f["name"]))
        previous_end = 0
        total = 0
        for i, function in enumerate(entries):
            offset, length = number(function["address"]), number(function["size"])
            if length <= 0 or offset < previous_end or offset + length > size:
                raise ValueError(f"overlapping/out-of-section function {function['name']} in {name}")
            previous_end = offset + length
            next_offset = number(entries[i + 1]["address"]) if i + 1 < len(entries) else size
            functions.append({"name": function["name"], "start": base + offset,
                              "end": base + offset + length, "size_bytes": length,
                              "next": base + next_offset, "report_unit": name,
                              "report_complete": complete_unit(unit)})
            total += length
        if total != number(unit.get("measures", {}).get("total_code", 0)):
            raise ValueError(f"function sizes do not equal reported total_code in {name}")
    functions.sort(key=lambda f: (f["start"], f["name"]))
    if any(a["end"] > b["start"] for a, b in zip(functions, functions[1:])):
        raise ValueError("overlapping functions across report units")
    return functions, coverage, sorted(unmapped)


def instruction_signatures(asm_root, candidates):
    """Read addressed assembly in one pass, retaining meaningful operands.

    Unlike the autodecompiler's clone discovery, this never masks relocations.
    check_match.py demonstrates why different calls and hi/lo targets matter.
    """
    if not asm_root.is_dir():
        raise ValueError("assembly root does not exist or is not a directory")
    ordered = sorted(candidates, key=lambda f: f["start"])
    starts = [f["start"] for f in ordered]
    instructions, labels = {}, {}
    for path in sorted(asm_root.rglob("*.s")):
        if "data" in path.relative_to(asm_root).parts:
            continue
        pending = []
        with path.open(encoding="utf-8") as stream:
            for line in stream:
                local = LOCAL_LABEL.match(line)
                if local:
                    pending.append(local[1])
                match = INSN.match(line)
                if not match:
                    continue
                pc = int(match[1], 16)
                for label in pending:
                    key = (path, label)
                    if key in labels and labels[key] != pc:
                        raise ValueError(f"ambiguous local label {label}")
                    labels[key] = pc
                pending.clear()
                i = bisect_right(starts, pc) - 1
                if i < 0 or pc >= ordered[i]["end"]:
                    continue
                text = re.sub(r"\s+", " ", match[2].split("#", 1)[0].strip())
                text = re.sub(r"\s*,\s*", ",", text)
                text = re.sub(r"\s*([()+-])\s*", r"\1", text)
                if pc in instructions:
                    old_text, _ = instructions[pc]
                    if old_text != text:
                        raise ValueError(f"conflicting assembly at {address(pc)}")
                instructions[pc] = (text, path)
    signatures = {}
    for f in ordered:
        if f["start"] % 4 or f["size_bytes"] % 4:
            continue
        sequence = []
        for pc in range(f["start"], f["end"], 4):
            if pc not in instructions:
                break
            text, path = instructions[pc]

            def local_offset(match):
                target = labels.get((path, match[0]))
                if target is not None and f["start"] <= target < f["end"]:
                    return f"@local+{target - f['start']}"
                return match[0]

            sequence.append(LOCAL_REF.sub(local_offset, text))
        else:
            signatures[f["start"]] = tuple(sequence)
    return signatures


def research_references(path):
    """Read address-index citations only; do not copy excerpts or game data."""
    references = []
    for line_no, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        match = re.match(r"^\|\s*`(?:0x)?([0-9a-fA-F]{8})`\s*\|", line)
        if not match:
            continue
        # Stop before the excerpt, which may contain unrelated Markdown links.
        columns = line.split("|", 4)
        for note in sorted(set(re.findall(r"\[[^]]+\]\(([^)]+\.md)\)", columns[3]))):
            references.append((int(match[1], 16), note, line_no))
    return sorted(references)


def rank_candidates(config, report, start=None, end=None, asm_root=None, research_index=None):
    spans = config_spans(config)
    code = [s for s in spans if s.kind in CODE_TYPES]
    if not code:
        raise ValueError("no configured code spans")
    start = min(s.start for s in code) if start is None else start
    end = max(s.end for s in code) if end is None else end
    if start < 0 or start >= end:
        raise ValueError("--start must be nonnegative and less than --end")
    functions, coverage, unmapped = report_inventory(report, spans)
    starts = [s.start for s in spans]
    counts, byte_counts = defaultdict(int), defaultdict(int)
    candidates = []
    for f in functions:
        if f["start"] >= end or f["end"] <= start:
            continue
        i = bisect_right(starts, f["start"]) - 1
        owner = spans[i] if i >= 0 else None
        if f["start"] < start or f["end"] > end:
            status = "range_boundary"
        elif owner is None or owner.kind not in CODE_TYPES or f["end"] > owner.end:
            status = "ownership_boundary"
        elif owner.kind == "c":
            status = ("owned_c_complete" if f["report_complete"] and owner.name == f["report_unit"]
                      else "owned_c_unverified")
        elif f["report_complete"]:
            status = "report_complete_without_c_owner"
        else:
            status = "unmatched"
        counts[status] += 1
        j = max(i, 0)
        while j < len(spans) and spans[j].start < min(f["end"], end):
            span = spans[j]
            if span.kind in CODE_TYPES:
                byte_counts[status] += max(0, min(f["end"], span.end, end) - max(f["start"], span.start, start))
            j += 1
        if status == "unmatched":
            f = dict(f, owner=owner.name, following_gap_bytes=max(0, min(f["next"], owner.end, end) - f["end"]))
            candidates.append(f)
    signatures = instruction_signatures(asm_root, candidates) if asm_root is not None else {}
    grouped = defaultdict(list)
    for f in candidates:
        signature = signatures.get(f["start"])
        if signature is not None:
            grouped[signature].append(f)
    groups, membership = [], {}
    for signature, members in grouped.items():
        if len(members) < 2:
            continue
        group_id = hashlib.sha256("\n".join(signature).encode("utf-8")).hexdigest()[:16]
        total = sum(f["size_bytes"] for f in members)
        groups.append({"id": group_id, "heuristic": True, "candidate_count": len(members),
                       "potential_gain_bytes": total,
                       "members": [address(f["start"]) for f in sorted(members, key=lambda f: f["start"])]})
        for f in members:
            membership[f["start"]] = (group_id, total)
    groups.sort(key=lambda g: (-g["potential_gain_bytes"], g["members"]))
    refs = research_references(research_index) if research_index is not None else []
    ref_addresses = [r[0] for r in refs]
    rows, research_groups = [], defaultdict(list)
    for f in candidates:
        group_id, gain = membership.get(f["start"], (None, f["size_bytes"]))
        first = bisect_right(ref_addresses, f["start"] - 1)
        last = bisect_right(ref_addresses, f["end"] - 1)
        evidence = [{"address": address(a), "note": note, "index_line": line,
                     "location": "entry" if a == f["start"] else "interior"}
                    for a, note, line in refs[first:last]]
        row = {"address": address(f["start"]), "end": address(f["end"]), "name": f["name"],
               "owner": f["owner"], "size_bytes": f["size_bytes"],
               "following_gap_bytes": f["following_gap_bytes"], "family_id": group_id,
               "family_gain_bytes": gain, "signature_available": f["start"] in signatures,
               "research": evidence}
        rows.append(row)
        for note in sorted({r["note"] for r in evidence}):
            research_groups[note].append(row)
    rows.sort(key=lambda r: (-r["family_gain_bytes"], -r["size_bytes"], r["address"], r["name"]))
    research = [{"note": note, "candidate_count": len(members),
                 "potential_gain_bytes": sum(r["size_bytes"] for r in members),
                 "members": sorted(r["address"] for r in members)}
                for note, members in research_groups.items()]
    research.sort(key=lambda r: (-r["potential_gain_bytes"], r["note"]))
    span_bytes = union_size((max(start, s.start), min(end, s.end)) for s in code
                           if max(start, s.start) < min(end, s.end))
    covered = intersection_size(coverage, code, start, end)
    function_bytes = sum(byte_counts.values())
    warnings = []
    if covered < span_bytes:
        warnings.append("Report does not cover all configured code spans in this range.")
    if unmapped:
        warnings.append("Some report units cannot be located in the current config; inventory may be stale.")
    if counts["owned_c_unverified"]:
        warnings.append("Incomplete/unverified C-owned functions are reserved, not offered as new work.")
    if counts["report_complete_without_c_owner"]:
        warnings.append("Report completion disagrees with assembly ownership; affected functions are excluded.")
    if counts["ownership_boundary"]:
        warnings.append("Functions crossing ownership boundaries are excluded; check config/report consistency.")
    if asm_root is None:
        warnings.append("No assembly supplied: byte ranking is available, similarity grouping is unavailable.")
    elif len(signatures) < len(candidates):
        warnings.append("Some candidates lack a complete addressed instruction sequence; they are not grouped.")
    return {
        "schema_version": 1, "range": {"start": address(start), "end_exclusive": address(end)},
        "ranking": "descending family potential bytes, function bytes, address, name",
        "grouping": "heuristic only; local labels/whitespace normalized; other operands preserved",
        "summary": {
            "configured_code_span_bytes": span_bytes, "report_covered_span_bytes": covered,
            "missing_report_span_bytes": span_bytes - covered, "reported_function_bytes": function_bytes,
            "covered_non_function_bytes": covered - function_bytes,
            "inventory_complete": (span_bytes > 0 and covered == span_bytes and not unmapped
                                   and not counts["ownership_boundary"]
                                   and not counts["report_complete_without_c_owner"]),
            "function_counts": dict(sorted(counts.items())), "function_bytes": dict(sorted(byte_counts.items())),
            "potential_gain_bytes": sum(r["size_bytes"] for r in rows),
            "signature_available_functions": len(signatures), "repetitive_families": len(groups),
            "research_candidate_bytes": sum(r["size_bytes"] for r in rows if r["research"]),
        },
        "unmapped_report_units": unmapped, "warnings": warnings,
        "families": groups, "research_groups": research, "candidates": rows,
    }


def human_output(result, limit):
    summary = result["summary"]
    bounds = result["range"]
    lines = [
        f"Range [{bounds['start']}, {bounds['end_exclusive']}): "
        f"{len(result['candidates'])} candidates, {summary['potential_gain_bytes']:,} potential code bytes",
        f"Inventory {'complete' if summary['inventory_complete'] else 'INCOMPLETE'}: "
        f"{summary['report_covered_span_bytes']:,}/{summary['configured_code_span_bytes']:,} span bytes; "
        f"{summary['covered_non_function_bytes']:,} covered non-function bytes (not gains)",
        f"{summary['repetitive_families']} heuristic families; "
        f"{summary['research_candidate_bytes']:,} research-cited candidate bytes. No match claims.",
        "Address       Bytes  Family bytes  Name",
    ]
    for row in result["candidates"][:limit]:
        lines.append(f"{row['address']} {row['size_bytes']:7} {row['family_gain_bytes']:13}  {row['name']}")
    if len(result["candidates"]) > limit:
        lines.append(f"Showing {limit}/{len(result['candidates'])}; --json includes all candidates.")
    lines.extend("WARNING: " + warning for warning in result["warnings"])
    return "\n".join(lines)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--input-root", type=Path, default=ROOT, help="root for config, report and optional asm")
    parser.add_argument("--config", type=Path, help="explicit splat YAML (default: INPUT_ROOT/config/splat.yaml)")
    parser.add_argument("--report", type=Path, help="objdiff report (default: build/report.json, then progress/report.json)")
    parser.add_argument("--asm-root", type=Path, help="read-only assembly root (default: INPUT_ROOT/asm if present)")
    parser.add_argument("--research-index", type=Path, help="optional port research ADDRESS_INDEX.md")
    parser.add_argument("--start", type=number, help="inclusive virtual address (default: first code span)")
    parser.add_argument("--end", type=number, help="exclusive virtual address (default: last code span)")
    parser.add_argument("--limit", type=int, default=15, help="human rows, not a JSON filter (default: 15)")
    parser.add_argument("--json", action="store_true", help="deterministic JSON, no timestamps, paths or game bytes")
    args = parser.parse_args(argv)
    if args.limit < 0:
        parser.error("--limit must be nonnegative")
    config_path = args.config or args.input_root / "config" / "splat.yaml"
    report_path = args.report or args.input_root / "build" / "report.json"
    if args.report is None and not report_path.is_file():
        report_path = args.input_root / "progress" / "report.json"
    asm_root = args.asm_root
    if asm_root is None and (args.input_root / "asm").is_dir():
        asm_root = args.input_root / "asm"
    try:
        config = yaml.safe_load(config_path.read_text(encoding="utf-8"))
        report = json.loads(report_path.read_text(encoding="utf-8"))
        if not isinstance(config, dict) or not isinstance(report, dict):
            raise ValueError("config and report must be objects")
        result = rank_candidates(config, report, args.start, args.end, asm_root, args.research_index)
    except (OSError, ValueError, KeyError, TypeError, IndexError, yaml.YAMLError) as exc:
        parser.exit(2, f"rank_candidates: {exc}\n")
    print(json.dumps(result, indent=2, sort_keys=True) if args.json else human_output(result, args.limit))
    return 0


if __name__ == "__main__":
    sys.exit(main())
