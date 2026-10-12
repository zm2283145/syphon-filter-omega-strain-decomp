typedef struct { int idx; unsigned int n; unsigned char b8; char pad; unsigned char bA; char pad2; int size; char pad3[0x204 - 0x10]; void *buf; } Obj4D50;
extern short D_00491432;
extern unsigned char D_00491430;
extern Obj4D50 *D_0052AC98[];
extern int func_002E6098(int id);
extern int Net_AllocZeroed(void *pp, unsigned long size);
extern void func_002FB3C0(void *pp);
int func_00314D50(int idx, unsigned int n)
{
    int ok, r;
    Obj4D50 **pp;
    Obj4D50 *o;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (func_002E6098(idx) != ok) return 0x17;
    if (idx >= 4) return 0x17;
    if (n > 256) return 0x17;
    if (n == 0) return 0x17;
    if (D_0052AC98[idx] == 0) {
        if (Net_AllocZeroed(&D_0052AC98[idx], 0x228) != 0) return 0x29;
    }
    pp = &D_0052AC98[idx];
    o = *pp;
    if (o == 0) return 0x29;
    if (o->buf) func_002FB3C0(&o->buf);
    r = Net_AllocZeroed(&o->buf, n * 8);
    if (r != 0) {
        func_002FB3C0(pp);
        *pp = 0;
        return 0x29;
    }
    if (o->buf == 0) return 0x29;
    o->n = n;
    o->idx = idx;
    o->size = 0x100;
    o->bA = 0;
    o->b8 = 0;
    return r;
}
