extern short D_00491432;
extern unsigned char D_00491430;
extern int D_0052AC98[];
extern int func_002E6098(int id);
int func_00314F58(int id, int *out)
{
    int ok;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (func_002E6098(id) != ok) return 0x17;
    if (out == 0) return 0x17;
    *out = D_0052AC98[id];
    return 0;
}
