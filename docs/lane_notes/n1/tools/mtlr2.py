import gdb, os
T = int(os.environ["T"]); N = int(os.environ.get("N", "1"))
gdb.execute("set pagination off")
def regs(expr):
    r = int(gdb.parse_and_eval("*(unsigned int*)&(%s)" % expr)); return [i for i in range(32) if r >> i & 1]
state = {"n": 0, "res": None}
class Fdsr(gdb.Breakpoint):
    def stop(self):
        if state["res"] is not None and gdb.selected_frame().older().name() == "mark_target_live_regs":
            print("  before fdsr: %s  b=%s" % (regs("((struct resources*)%d)->regs[0]" % state["res"]), gdb.selected_frame().older().read_var("b")))
            try:
                print("  tinfo:", gdb.selected_frame().older().read_var("tinfo"))
            except Exception as e: print(e)
        return False
class Fin(gdb.FinishBreakpoint):
    def stop(self):
        print("  final: %s" % regs("((struct resources*)%d)->regs[0]" % state["res"])); state["res"] = None
        return False
class M(gdb.Breakpoint):
    def stop(self):
        t = gdb.parse_and_eval("target")
        if int(t) and int(t["fld"][0]["rtint"]) == T:
            state["n"] += 1
            print("MTLR %d #%d from %s" % (T, state["n"], gdb.selected_frame().older().name()))
            state["res"] = int(gdb.parse_and_eval("res")); Fin(gdb.selected_frame(), internal=True)
        return False
M("mark_target_live_regs", internal=True); Fdsr("find_dead_or_set_registers", internal=True)
gdb.execute("run")
