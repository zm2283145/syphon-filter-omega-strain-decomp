extern unsigned char D_00490900;
extern short D_004908EE;
extern char D_005297F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int func_00302218(void *);
extern int func_002FC7A0(void);
int func_002FB840(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FC7A0();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    if (r == 0 && D_004908EE == 0) {
        if (func_00302218(D_005297F0)) return 0x1A;
        D_00490900 = 0;
    }
    return r;
}