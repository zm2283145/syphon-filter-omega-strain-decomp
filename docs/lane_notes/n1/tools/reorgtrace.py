# gdb -x reorgtrace.py --args cc1 file.i -quiet -O2 -G0 -w -o out.s
# env WATCH="448,287" : print live regs result for these target uids
import gdb, os
WATCH = set(int(x) for x in os.environ.get("WATCH", "").split(",") if x)
gdb.execute("set pagination off")
def uid(v):
    try:
        if int(v) == 0: return -1
        return int(v["fld"][0]["rtint"])
    except Exception: return -2
class Fin(gdb.FinishBreakpoint):
    def __init__(self, frame, t, res):
        super().__init__(frame, internal=True); self.t = t; self.res = res
    def stop(self):
        r = int(gdb.parse_and_eval("*(unsigned int*)&((struct resources*)%d)->regs[0]" % self.res))
        regs = [i for i in range(32) if r >> i & 1]
        print("   MTLR result target=%d regs=%s" % (self.t, regs))
        return False
class B(gdb.Breakpoint):
    def __init__(self, spec, kind):
        super().__init__(spec, internal=True); self.kind = kind
    def stop(self):
        f = gdb.selected_frame()
        if self.kind == "mtlr":
            t = uid(gdb.parse_and_eval("target"))
            caller = f.older().name()
            print("MTLR target=%d from %s" % (t, caller))
            if t in WATCH:
                Fin(f, t, int(gdb.parse_and_eval("res")))
        elif self.kind == "upd":
            print("UPD insn=%d where=%d from %s" % (uid(gdb.parse_and_eval("insn")), uid(gdb.parse_and_eval("where")), f.older().name()))
        elif self.kind == "fsft":
            print("FSFT insn=%d thread=%d opp=%d likely=%s own=%s" % (uid(gdb.parse_and_eval("insn")), uid(gdb.parse_and_eval("thread")), uid(gdb.parse_and_eval("opposite_thread")), gdb.parse_and_eval("likely"), gdb.parse_and_eval("own_thread")))
        elif self.kind == "simple":
            print("SIMPLE non_jumps=%s" % gdb.parse_and_eval("non_jumps_p"))
        elif self.kind == "eager":
            print("EAGER")
        elif self.kind == "relax":
            print("RELAX")
        return False
B("mark_target_live_regs", "mtlr"); B("update_block", "upd"); B("fill_slots_from_thread", "fsft")
B("fill_simple_delay_slots", "simple"); B("fill_eager_delay_slots", "eager"); B("relax_delay_slots", "relax")
gdb.execute("run")
