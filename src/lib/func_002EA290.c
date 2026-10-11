extern unsigned char D_0048C4D7, D_0048C4DC;
extern char D_005253F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int func_002DE828(signed char, void *, void *, void *, void *, void *);
int func_002EA290(signed char a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DE828(a, b, c, d, e, f);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}