extern unsigned char D_0048C4D7, D_0048C4DC;
extern char D_005253F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int func_002E2BB8(void *);
int func_002EC3C8(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E2BB8(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}