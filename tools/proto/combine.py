#!/usr/bin/env python3
"""Combine the per-prototype matches into map.tsv, name proposals, renames and layout.

usage: combine.py
reads cache/{retail,early,earlier}.pkl, cache/match_{early,earlier}.pkl,
      config/symbol_addrs.txt (read only)
writes map.tsv, names_proposed.txt, names_proposed_renames.txt, renames.tsv,
       names_review.txt, layout.txt, layout_objects.txt, vtables.tsv, coverage.txt
"""
import sys, os, re, pickle, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import *
from demangle import demangle, c_ident, ident, OPID

LIBC = set('''abort abs atexit atof atoi atol bsearch calloc clearerr div exit fclose feof ferror fflush fgetc fgetpos
fgets fopen fprintf fputc fputs fread free freopen frexp fscanf fseek fsetpos ftell fwrite getc getchar getenv gets
isalnum isalpha iscntrl isdigit isgraph islower isprint ispunct isspace isupper isxdigit labs ldexp ldiv localeconv
malloc mblen mbstowcs mbtowc memchr memcmp memcpy memmove memset modf perror printf putc putchar puts qsort raise rand
realloc remove rename rewind scanf setbuf setlocale setvbuf signal sprintf srand sscanf strcat strchr strcmp strcoll
strcpy strcspn strerror strftime strlen strncat strncmp strncpy strpbrk strrchr strspn strstr strtod strtok strtol
strtoul strxfrm system time tmpfile tmpnam tolower toupper ungetc vfprintf vprintf vsprintf vsnprintf snprintf
wcstombs wctomb sin cos tan asin acos atan atan2 sinh cosh tanh exp log log10 pow sqrt ceil floor fabs fmod
sinf cosf tanf sqrtf atan2f fabsf floorf ceilf powf expf logf fmodf asinf acosf atanf clock difftime mktime
gmtime localtime asctime ctime strdup stricmp strnicmp strcasecmp strncasecmp bzero bcopy memccpy itoa
fiprintf iprintf siprintf log10f log2 log2f exp2 cbrt hypot hypotf memalign strupr strlwr
open close read write lseek ioctl stat fstat unlink isatty sbrk kill getpid mkdir rmdir chdir getcwd'''.split())
NEWLIB_RANGE = (0x00121B00, 0x0012ECD0)  # newlib block in retail (repo names these Newlib_*)


def newlib_name(base):
    parts = [p for p in base.strip('_').split('_') if p]
    return 'Newlib_' + ''.join(p[:1].upper() + p[1:] for p in parts)

UNSTABLE = re.compile(r'nScript\d+|__arraydtor\$|@LOCAL@|\$\d+')
NSDROP = re.compile(r'^(n[A-Z].*|@unnamed@.*|Metrowerks|ScriptPriv)$')


def simplify_targs(c):
    # drop default-ish template arguments (allocators, comparators)
    c = re.sub(r',(cAllocator|std::allocator|std::less|Metrowerks::\w+)<[^<>]*(<[^<>]*>)?[^<>]*>', '', c)
    return c


def split_top(s, sep):
    out, depth, cur = [], 0, ''
    i = 0
    while i < len(s):
        ch = s[i]
        if ch == '<': depth += 1
        elif ch == '>': depth -= 1
        if depth == 0 and s.startswith(sep, i):
            out.append(cur); cur = ''; i += len(sep); continue
        cur += ch; i += 1
    out.append(cur)
    return out


def short_arg(a, depth=0):
    a = re.sub(r'\b(const|volatile|unsigned)\b', '', a).strip()
    ptr = 'Ptr' * re.search(r'[*&\s]*$', a).group().count('*')
    a = a.rstrip('*& ')
    seg = split_top(a, '::')[-1].strip()
    if '<' in seg:
        name = seg[:seg.index('<')]
        inner = split_top(seg[seg.index('<') + 1:seg.rindex('>')], ',')
        if depth < 1 and inner and inner[0].strip():
            return name + '_' + short_arg(inner[0], depth + 1) + ptr
        return name + ptr
    return seg + ptr


def short_class(c):
    if '<' not in c:
        return c
    name = c[:c.index('<')]
    args = split_top(c[c.index('<') + 1:c.rindex('>')], ',')
    args = [short_arg(x) for x in args if x.strip()]
    return name + ('_' + '_'.join(args) if args else '')


def name_for(sym, raddr=None):
    """C-identifier for a prototype symbol following repo conventions."""
    pretty, info = demangle(sym)
    if UNSTABLE.search(sym):
        return None, pretty, info
    if sym.startswith('__sinit_'):
        f = sym[len('__sinit_'):].strip()
        f = re.sub(r'\.(cc|cpp|c)$', '', f)
        return 'StaticInit_' + ident(f), pretty, info
    cls = [simplify_targs(c) for c in info['cls']]
    kind = info['kind']
    if not cls and kind == 'op':
        return OPID.get(info['base'][2:], 'op'), pretty, info
    if not cls or kind == 'data':
        base = info['base'] if info['params'] is not None or kind == 'data' else sym
        if base in LIBC:
            return 'Libc_' + base[:1].upper() + base[1:], pretty, info
        if raddr is not None and NEWLIB_RANGE[0] <= raddr < NEWLIB_RANGE[1]:
            return ident(newlib_name(base)), pretty, info
        return ident(base), pretty, info
    keep = [c for c in cls if not NSDROP.match(c)]
    if not keep:  # free function inside a namespace: keep the namespace
        keep = [c for c in cls if not c.startswith('@unnamed@')] or []
    info2 = dict(info); info2['cls'] = keep
    # build identifier
    parts = []
    for c in keep:
        parts.append(short_class(c))
    b = info['base']
    if kind == 'ctor': m = 'ctor'
    elif kind == 'dtor': m = 'dtor'
    elif kind == 'op': m = OPID.get(b[2:], 'op')
    elif kind == 'conv':
        m = re.sub(r'^.*?_(opCast.*)$', r'\1', c_ident(sym)[0])
    else: m = b
    if not parts:
        return ident(m), pretty, info
    return re.sub(r'_{2,}', '_', ident('_'.join(parts) + '_' + m)), pretty, info


def param_suffix(info):
    ps = info.get('params') or []
    if not ps or ps == ['void']:
        return 'void'
    out = []
    for p in ps:
        p = re.sub(r'\bconst\b|\bvolatile\b', '', p)
        p = simplify_targs(p)
        p = p.replace('unsigned ', 'u').replace('*', 'P').replace('&', 'R')
        p = re.sub(r'<.*>', '', p)
        p = p.split('::')[-1]
        out.append(re.sub(r'[^A-Za-z0-9]', '', p))
    if len(out) > 4:
        out = out[:4] + ['etc']
    return '_'.join(out)


def main():
    R = pickle.load(open(os.path.join(CACHE, 'retail.pkl'), 'rb'))['funcs']
    raddr = {f['addr']: f for f in R}
    M = {}
    VT = {}
    for w in ('early', 'earlier'):
        d = pickle.load(open(os.path.join(CACHE, 'match_%s.pkl' % w), 'rb'))
        M[w] = d['map']; VT[w] = d['vt']
    rank = {'high': 3, 'medium': 2, 'low': 1, None: 0}

    rows = {}
    for a, f in raddr.items():
        e = M['early'].get(a); l = M['earlier'].get(a)
        ne = name_for(e['pname'], a)[0] if e else None
        nl = name_for(l['pname'], a)[0] if l else None
        note = []
        if e and l:
            agree = (ne == nl) if (ne and nl) else (e['pname'] == l['pname'])
            if agree:
                conf = max(e['conf'], l['conf'], key=lambda c: rank[c])
                if conf == 'medium' and min(e['sim'], l['sim']) >= 0.7 and e['conf'] == l['conf'] == 'medium':
                    conf = 'high'; note.append('2-proto-agree-promoted')
                if conf == 'low' and min(e['sim'], l['sim']) >= 0.6:
                    conf = 'medium'
                best = e
            else:
                best = e if rank[e['conf']] >= rank[l['conf']] else l
                conf = 'medium' if rank[best['conf']] >= 2 else 'low'
                note.append('protos-disagree: early=%s earlier=%s' % (e['pdem'], l['pdem']))
        elif e or l:
            best = e or l
            conf = best['conf']
            note.append('only-' + ('early' if e else 'earlier'))
        else:
            best = None; conf = None
        if best is not None and best['disagree'] > best['agree'] and conf == 'high':
            conf = 'medium'; note.append('xref-conflict')
        rows[a] = dict(e=e, l=l, best=best, conf=conf, note=note)

    # --------------- names ------------------
    existing = {f['addr']: f['name'] for f in R}
    symfile = {}
    for line in open(os.path.join(REPO, 'config', 'symbol_addrs.txt')):
        m = re.match(r'\s*(\S+)\s*=\s*0x([0-9A-Fa-f]+);', line)
        if m:
            symfile.setdefault(int(m.group(2), 16), m.group(1))
    allnames_fixed = set(existing.values()) | set(symfile.values())
    cand = {}
    for a, r in rows.items():
        b = r['best']
        if not b:
            continue
        nm, pretty, info = name_for(b['pname'], a)
        r['ident'] = nm; r['pretty'] = pretty; r['info'] = info
        if nm:
            cand[a] = nm
    # disambiguate repeats (overloads / same method name in identical instantiations)
    groups = collections.defaultdict(list)
    for a, nm in cand.items():
        groups[nm].append(a)
    final = {}
    for nm, addrs in groups.items():
        if len(addrs) == 1:
            final[addrs[0]] = nm
            continue
        used = set()
        for a in sorted(addrs):
            suf = param_suffix(rows[a]['info'])
            n2 = nm + '_' + suf
            k = 2
            while n2 in used:
                n2 = '%s_%s_%d' % (nm, suf, k); k += 1
            used.add(n2)
            final[a] = n2
    # avoid clashing with names that stay on other addresses
    for a, nm in list(final.items()):
        clash = [x for x, n in existing.items() if n == nm and x != a]
        if clash:
            k = 2
            while ('%s_%d' % (nm, k)) in allnames_fixed:
                k += 1
            final[a] = '%s_%d' % (nm, k)
            rows[a]['note'].append('renamed-to-avoid-clash-with-%08X' % clash[0])

    # --------------- outputs ------------------
    out = P1
    with open(os.path.join(out, 'map.tsv'), 'w') as fo:
        fo.write('retail_addr\tretail_name\tsize\tconfidence\tproposed_name\tdemangled\tearly_addr\tearly_symbol\t'
                 'early_method\tearly_sim\tearlier_addr\tearlier_symbol\tearlier_method\tearlier_sim\txref_agree\t'
                 'xref_disagree\tobject\tnotes\n')
        for a in sorted(rows):
            r = rows[a]; e, l, b = r['e'], r['l'], r['best']
            fo.write('\t'.join([
                '%08X' % a, existing[a], str(raddr[a]['size']), r['conf'] or 'none', final.get(a, ''),
                r.get('pretty', ''),
                '%08X' % e['paddr'] if e else '', e['pname'] if e else '', e['method'] if e else '',
                str(e['sim']) if e else '',
                '%08X' % l['paddr'] if l else '', l['pname'] if l else '', l['method'] if l else '',
                str(l['sim']) if l else '',
                str(b['agree']) if b else '', str(b['disagree']) if b else '',
                (b.get('obj') or '') if b else '', '; '.join(r['note'])]) + '\n')

    prop, propr, ren, rev = [], [], [], []
    for a in sorted(rows):
        r = rows[a]
        if a not in final:
            continue
        nm = final[a]; old = existing[a]; cur = symfile.get(a, old)
        if cur == nm:
            continue
        ev = '%s sim=%s/%s %s' % (r['best']['method'], r['e']['sim'] if r['e'] else '-', r['l']['sim'] if r['l'] else '-',
                                  ('; '.join(r['note'])))
        line = '%s = 0x%08X; // type:func' % (nm, a)
        if r['conf'] == 'high':
            if old.startswith('func_') and a not in symfile:
                prop.append(line + '  // %s' % r['pretty'])
            else:
                if old.startswith('Script_') and 'nScript' in r['best']['pname']:
                    continue
                propr.append(line + '  // was %s; %s' % (cur, r['pretty']))
                if re.search(r'_v[0-9A-F]{2}$', cur): kind = 'vslot->name'
                elif cur.split('_')[0].lower().lstrip('c') in nm.lower(): kind = 'same-prefix'
                elif cur.lower().replace('_', '') == nm.lower().replace('_', ''): kind = 'spelling'
                else: kind = 'different'
                ren.append('%08X\t%s\t%s\t%s\t%s\t%s' % (a, cur, nm, kind, r['pretty'], ev))
        elif r['conf'] == 'medium':
            rev.append('%08X\t%s\t%s\t%s\t%s' % (a, cur, nm, r['pretty'], ev))
    # unstable names (script thunks etc.) of currently unnamed functions -> review only
    for a in sorted(rows):
        r = rows[a]
        if r.get('ident') is None and r['best'] and existing[a].startswith('func_'):
            rev.append('%08X\t%s\t%s\t%s\t%s' % (a, existing[a], '(unstable proto name)', r['pretty'], r['best']['method']))
    hdr = ('// P1 proposals: high-confidence prototype names for retail functions currently named func_XXXXXXXX.\n'
           '// Format matches config/symbol_addrs.txt; trailing comment = demangled prototype name.\n')
    open(os.path.join(out, 'names_proposed.txt'), 'w').write(hdr + '\n'.join(prop) + '\n')
    open(os.path.join(out, 'names_proposed_renames.txt'), 'w').write(
        '// P1: high-confidence prototype names for functions that ALREADY have a non-func_ name.\n'
        '// For owner review only - do not apply blindly (see renames.tsv for evidence).\n' + '\n'.join(propr) + '\n')
    open(os.path.join(out, 'renames.tsv'), 'w').write('addr\told_name\tnew_name\tkind\tprototype_name\tevidence\n' + '\n'.join(ren) + '\n')
    open(os.path.join(out, 'names_review.txt'), 'w').write(
        '// P1 medium-confidence (or protos-disagree) mappings; evidence = method, similarity early/earlier, notes\n'
        'addr\tcurrent_name\tproposed\tprototype_name\tevidence\n' + '\n'.join(rev) + '\n')

    # --------------- vtables -----------------
    with open(os.path.join(out, 'vtables.tsv'), 'w') as fo:
        fo.write('retail_vtable_addr\tproto_symbol\tclass\tslots_proto\tslots_voting\tproto\n')
        seen = set()
        for w in ('early', 'earlier'):
            for vn, (start, v, mapped, n) in sorted(VT[w].items(), key=lambda x: x[1][0]):
                if (start, vn) in seen:
                    continue
                seen.add((start, vn))
                fo.write('%08X\t%s\t%s\t%d\t%d/%d\t%s\n' % (start, vn, demangle('x__' + vn[6:] + 'Fv')[1]['cls'] and
                                                         '::'.join(demangle('x__' + vn[6:] + 'Fv')[1]['cls']) or vn[6:],
                                                         n, v, mapped, w))

    # --------------- layout ------------------
    units = collections.OrderedDict()
    for f in R:
        units.setdefault(f['unit'], []).append(f['addr'])
    lay = []
    for u, addrs in units.items():
        objs = collections.Counter()
        for a in addrs:
            b = rows[a]['best']
            if b and rows[a]['conf'] in ('high', 'medium'):
                o = b.get('obj') or (('inline-only:' + b['src']) if b.get('src') else '')
                if o:
                    objs[o] += 1
        if objs:
            o, k = objs.most_common(1)[0]
            lay.append([u, min(addrs), len(addrs), o, k, 'mapped' if k == len(addrs) else 'majority'])
        else:
            hint = [rows[a]['best']['pname'] for a in addrs if rows[a]['best'] and rows[a]['conf'] in ('high', 'medium')]
            lay.append([u, min(addrs), len(addrs), '', 0, ('nodebug-lib:' + hint[0]) if hint else 'none'])
    # infer unmapped units between two units of the same object
    for i, row in enumerate(lay):
        if row[3] or row[5] != 'none':
            continue
        p = next((lay[j][3] for j in range(i - 1, -1, -1) if lay[j][3]), '')
        n = next((lay[j][3] for j in range(i + 1, len(lay)) if lay[j][3]), '')
        # nearest mapped neighbours within 8 units
        p = next((lay[j][3] for j in range(i - 1, max(-1, i - 9), -1) if lay[j][3]), '')
        n = next((lay[j][3] for j in range(i + 1, min(len(lay), i + 9)) if lay[j][3]), '')
        if p and p == n:
            row[3] = p; row[5] = 'inferred-between'
    def short(o):
        pre = ''
        if o.startswith('inline-only:'):
            pre = '(inline-only) '; o = o[len('inline-only:'):]
        o = o.replace('\\', '/')
        m = re.search(r'/SFO/Code/(.*)$', o, re.I)
        if m: return pre + m.group(1)
        m = re.search(r'PS2 Support/(.*)$', o, re.I)
        if m: return pre + 'CW_PS2Support/' + m.group(1)
        return o
    with open(os.path.join(out, 'layout.txt'), 'w') as fo:
        fo.write('# splat unit -> original source object (from prototype DWARF compile units)\n')
        fo.write('# unit\tstart\tnfuncs\tsource (relative to C:\\SFO\\Code)\tfuncs_mapped_to_it\thow\n')
        for u, st, n, o, k, how in lay:
            fo.write('%s\t%08X\t%d\t%s\t%d\t%s\n' % (u, st, n, short(o) if o else '-', k, how))
    # object runs
    runs = []
    for u, st, n, o, k, how in lay:
        if runs and runs[-1][0] == o:
            runs[-1][2] += 1; runs[-1][3] += n
        else:
            runs.append([o, st, 1, n])
    with open(os.path.join(out, 'layout_objects.txt'), 'w') as fo:
        fo.write('# contiguous retail address runs per original source object\n# start\tunits\tfuncs\tsource\n')
        for o, st, nu, nf in runs:
            fo.write('%08X\t%d\t%d\t%s\n' % (st, nu, nf, short(o) if o else '-'))

    # --------------- coverage ----------------
    rep = [f for f in R if f['inreport']]
    c = collections.Counter(rows[f['addr']]['conf'] or 'none' for f in rep)
    unnamed = [f for f in rep if f['name'].startswith('func_')]
    cu = collections.Counter(rows[f['addr']]['conf'] or 'none' for f in unnamed)
    ce = collections.Counter((M['early'].get(f['addr']) or {}).get('conf', 'none') for f in rep)
    cl = collections.Counter((M['earlier'].get(f['addr']) or {}).get('conf', 'none') for f in rep)
    with open(os.path.join(out, 'coverage.txt'), 'w') as fo:
        fo.write('report.json functions: %d\n' % len(rep))
        for k in ('high', 'medium', 'low', 'none'):
            fo.write('%-7s combined %5d   early-only-run %5d   earlier-only-run %5d   (of func_ unnamed: %d/%d)\n' %
                     (k, c[k], ce[k], cl[k], cu[k], len(unnamed)))
        fo.write('names_proposed (func_ -> name): %d\nrenames (existing name differs, high): %d\nreview (medium): %d\n'
                 % (len(prop), len(ren), len(rev)))
        lc = collections.Counter(how.split(':')[0] for *_, how in lay)
        fo.write('layout units: %s\n' % dict(lc))
    print(open(os.path.join(out, 'coverage.txt')).read())


if __name__ == '__main__':
    main()
