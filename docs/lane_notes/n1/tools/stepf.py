import gdb, os
T = int(os.environ["T"]); NSTEP = int(os.environ.get("NSTEP", "80"))
gdb.execute("set pagination off")
def uid(v):
    try: return int(v["fld"][0]["rtint"]) if int(v) else -1
    except Exception: return -2
gdb.execute("break mark_target_live_regs if target != 0 && target->fld[0].rtint == %d" % T)
gdb.execute("run")
gdb.execute("delete")
gdb.execute("break find_dead_or_set_registers")
gdb.execute("continue")
gdb.execute("delete")
for i in range(NSTEP):
    gdb.execute("next", to_string=True)
    f = gdb.selected_frame()
    if f.name() != "find_dead_or_set_registers": print("left", f.name()); break
    line = f.find_sal().line
    try:
        ins = f.read_var("insn"); s = "insn=%d code=%d" % (uid(ins), int(gdb.parse_and_eval("*(unsigned short*)%d" % int(ins))) if int(ins) else -1)
    except Exception as e: s = "?"
    r = int(gdb.parse_and_eval("*(unsigned*)&res->regs[0]"))
    print(line, s, [i for i in range(32) if r >> i & 1])
