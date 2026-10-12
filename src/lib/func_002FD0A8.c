typedef struct { unsigned char flag; char pad[3]; int x4; int x8; } S2FD0A8;
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern S2FD0A8 D_005297E0;
extern int func_002FE7C0(unsigned short);
extern int func_002FDA18(unsigned short, unsigned char);
extern int func_002FE168(void);
int func_002FD0A8(unsigned char k)
{
    unsigned int i = 0;
    int r;
    if (D_004908EC != 1) return 5;
    for (; i < D_004908F0; i++) {
        if (func_002FE7C0(i) == 1) {
            r = func_002FDA18(i, k);
            if (r) return r;
        }
    }
    if (D_005297E0.flag == 1 && k == D_005297E0.flag) {
        r = func_002FE168();
        if (r) return r;
    }
    return 0;
}
