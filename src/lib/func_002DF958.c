extern unsigned short D_0058D178;
extern char D_005880A0[];
extern unsigned int func_002DCD20(unsigned short);
extern int func_002DD280(void);
extern void Net_DispatchRecv(int, int, int, int, unsigned short);
void func_002DF958(unsigned short a, unsigned short b, int c, unsigned short d)
{
    unsigned int h = func_002DCD20(a);
    if (h >= 4) return;
    if (c == 0) return;
    if (d == 0) return;
    D_005880A0[0] = 0;
    D_0058D178 = 0;
    Net_DispatchRecv(func_002DD280(), h, b, c, d);
}
