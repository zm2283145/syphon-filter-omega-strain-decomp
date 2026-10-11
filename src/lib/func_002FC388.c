extern unsigned char D_00490900;
extern char D_005297F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int func_002FD718(void *, void *);
int func_002FC388(void *a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD718(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}