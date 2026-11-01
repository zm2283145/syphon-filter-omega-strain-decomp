import gdb, os
T = int(os.environ["T"])
gdb.execute("set pagination off")
def uid(v):
    try: return int(v["fld"][0]["rtint"]) if int(v) else -1
    except Exception: return -2
class W(gdb.Breakpoint):
    def stop(self):
        f = gdb.selected_frame(); s = ""
        while f is not None:
            if f.name() == "mark_target_live_regs":
                try: s = "insn=%d real=%d" % (uid(f.read_var("insn")), uid(f.read_var("real_insn")))
                except Exception as e: s = str(e)
                break
            f = f.older()
        r = int(gdb.parse_and_eval("*(unsigned*)&current_live_regs"))
        print("  clr=%s %s" % ([i for i in range(32) if r >> i & 1], s))
        return False
class D(gdb.Breakpoint):
    def stop(self):
        print("FDSR"); gdb.execute("delete"); return True
class M(gdb.Breakpoint):
    def stop(self):
        t = gdb.parse_and_eval("target")
        if int(t) and uid(t) == T:
            print("MTLR b=?")
            W("*(unsigned*)&current_live_regs", gdb.BP_WATCHPOINT, internal=True)
            D("find_dead_or_set_registers", internal=True)
            self.enabled = False
        return False
M("mark_target_live_regs", internal=True)
gdb.execute("run")
