extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern int func_002FE7C0(unsigned short);
extern int func_002FCE88(unsigned short);
int func_002FCFE8(void)
{
    unsigned int i = 0;
    int r;
    if (D_004908EC != 1) return 5;
    for (; i < D_004908F0; i++) {
        if (func_002FE7C0(i) == 1) {
            r = func_002FCE88(i);
            if (r) return r;
        }
    }
    return 0;
}
