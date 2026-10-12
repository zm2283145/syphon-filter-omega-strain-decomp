typedef struct { char pad[0x204]; int sub; } Obj4EA8;
extern short D_00491432;
extern unsigned char D_00491430;
extern Obj4EA8 *D_0052AC98[];
extern int func_002E6098(int id);
extern void func_002FB3C0(void *p);
int func_00314EA8(int idx)
{
    int ok;
    Obj4EA8 **p;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (func_002E6098(idx) != ok) return 0x17;
    if (idx >= 4) return 0x17;
    p = &D_0052AC98[idx];
    if (*p == 0) return 0x17;
    if ((*p)->sub) func_002FB3C0(&(*p)->sub);
    func_002FB3C0(p);
    *p = 0;
    return 0;
}
