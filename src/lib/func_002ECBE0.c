extern unsigned char D_0048C4D7, D_0048C4DC;
extern char D_005253F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern void *memset(void *, int, unsigned int);
int func_002ECBE0(int *p)
{
    int r;
    unsigned char v;
    if (D_0048C4D7 != 1) return 0x11;
    v = D_0048C4DC;
    if (v != D_0048C4D7) return 0x2B;
    if (p == 0) return 0x17;
    r = RecursiveLock_Acquire(D_005253F0, 0);
    if (r) return 0x2B;
    memset(p, 0, 0x10);
    *p = v;
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}