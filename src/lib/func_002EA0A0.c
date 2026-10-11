extern unsigned char D_0048C4D7, D_0048C4DC;
extern char D_005253F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int Net_SendTyped(signed char, void *, void *, void *, void *, void *, void *);
int Net_SendLocked(signed char a, void *b, void *c, void *d, void *e, void *f, void *g)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = Net_SendTyped(a, b, c, d, e, f, g);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
