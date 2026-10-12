extern void *memset(void *, int, unsigned int);
extern short D_004908EE;
extern char D_005297F0[];
extern char D_005297E0[];
unsigned int D_00490900[1] = { 0x0 };
extern unsigned short D_004908F0;
extern int D_004908F4;
extern unsigned char D_004908EC;
extern int func_003021D0(char *);
extern int func_002F5BB0(void);
extern int func_003010C8(int);
extern void func_002F80C0(int, int);
int func_002FB788(int a)
{
    int r;
    if (D_004908EE == 0) {
        if (func_003021D0(D_005297F0)) return 0x1A;
        (*(unsigned char*)D_00490900) = 1;
        r = func_003010C8(func_002F5BB0());
        if (r) return r;
        D_004908F4 = 0;
        D_004908F0 = 0;
        memset(D_005297E0, 0, 0xC);
        func_002F80C0(0, a);
        D_004908EC = 1;
    }
    D_004908EE++;
    return 0;
}
