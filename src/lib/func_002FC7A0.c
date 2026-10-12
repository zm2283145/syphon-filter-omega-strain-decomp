extern short D_004908EE;
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern int *D_004908F4;
extern int D_004908F8;
extern int D_004908FC;
extern unsigned char D_005297E0;
extern int func_002FE7C0(unsigned short);
extern int func_002FCE88(unsigned short);
extern int func_002FE5A8(unsigned short);
extern void func_002FC928(void);
extern int func_002F5C10(void);
extern int func_003010C8(int);
extern int func_002FB3C0(void *);
extern void func_002F95F8(int);
int func_002FC7A0(void)
{
    unsigned short i = 0;
    int r;
    if (D_004908EE <= 0) return 5;
    if (D_004908EC != 1) return 5;
    if (D_004908EE == 1) {
        for (; i < D_004908F0; i++) {
            if (D_004908F4[i]) {
                if (func_002FE7C0(i) == 1) func_002FCE88(i);
                else func_002FE5A8(i);
            }
        }
        if (D_005297E0 == 1) func_002FC928();
        r = func_003010C8(func_002F5C10());
        if (r) return r;
        if (D_004908F4) func_002FB3C0(&D_004908F4);
        D_004908F4 = 0;
        D_004908F0 = 0;
        if (D_004908F8) {
            func_002FB3C0(&D_004908F8);
            D_004908FC = 0;
        }
        func_002F95F8(0);
        D_004908EC = 0;
    }
    D_004908EE--;
    return 0;
}
