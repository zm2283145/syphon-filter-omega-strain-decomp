/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct Obj5028 Obj5028;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_002E6098(int id);
extern int func_00314F58(int idx, Obj5028 **out);
int __attribute__((weak, section(".dtors_drop"))) func_00314FE0(Obj5028 *o) { return 0; }
int func_00315028(int idx, Obj5028 **out)
{
    int ok, v, r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    v = func_002E6098(idx);
    if (v != ok) return 0x17;
    r = func_00314F58(idx, out);
    if (r != 0) return r;
    return func_00314FE0(*out) == v ? 0 : 0x29;
}
