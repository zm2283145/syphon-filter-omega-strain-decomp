extern unsigned char D_00490900;
extern char D_005297F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int func_002FD280(unsigned short, unsigned short, unsigned short, void *, void *, void *, unsigned short);
int func_002FBE18(unsigned short a, unsigned short b, unsigned short c, void *d, void *e, void *f, unsigned short g)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD280(a, b, c, d, e, f, g);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}