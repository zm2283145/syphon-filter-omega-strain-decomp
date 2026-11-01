import gdb, os
T = int(os.environ["T"])
gdb.execute("set pagination off")
def uid(v):
    try: return int(v["fld"][0]["rtint"]) if int(v) else -1
    except Exception: return -2
class Step(gdb.Breakpoint):
    # breakpoint at each loop iteration: use 'switch' line? we instead break at mark_referenced_resources calls from fdsr
    def stop(self):
        f = gdb.selected_frame()
        if f.older() is None or f.older().name() != "find_dead_or_set_registers": return False
        fo = f.older()
        try:
            r = int(gdb.parse_and_eval("*(unsigned*)&((struct resources*)%d)->regs[0]" % int(fo.read_var("res"))))
            print("  fdsr insn=%d res=%s" % (uid(fo.read_var("insn")), [i for i in range(32) if r >> i & 1]))
        except Exception as e: print(e)
        return False
class D(gdb.Breakpoint):
    def stop(self):
        f = gdb.selected_frame()
        if f.older().name() == "mark_target_live_regs":
            print("FDSR start target=%d" % uid(f.read_var("target")))
            Step("mark_referenced_resources", internal=True); Step("mark_set_resources", internal=True)
            self.enabled = False
        return False
class M(gdb.Breakpoint):
    def stop(self):
        t = gdb.parse_and_eval("target")
        if int(t) and uid(t) == T:
            D("find_dead_or_set_registers", internal=True); self.enabled = False
        return False
M("mark_target_live_regs", internal=True)
gdb.execute("run")
