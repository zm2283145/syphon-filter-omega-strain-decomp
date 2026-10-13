extern unsigned char D_0048C4D7, D_0048C4DC;
extern unsigned int D_0048C4D8;
extern char D_005253F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int func_002E4EA8(void);
extern int func_00302218(void *);
int func_002E9648(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4D8 == 0) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (D_0048C4D8 >= 2) {
        D_0048C4D8--;
        return 0;
    }
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E4EA8();
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    if (r == 0) {
        if (func_00302218(D_005253F0)) return 0x2B;
        D_0048C4DC = 0;
        D_0048C4D7 = 0;
        D_0048C4D8 = 0;
    }
    return r;
}

