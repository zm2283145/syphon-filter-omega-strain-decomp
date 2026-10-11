extern unsigned int D_0048C450;
extern int D_00598400;
extern int func_002DEA68(unsigned int);
extern int func_002DE880(int, unsigned int, int, int, int, unsigned short *);
int func_002DEBE0(unsigned int a)
{
    unsigned short v;
    if (a >= 0x1000) return 0x17;
    if (D_0048C450 >= 4) return 8;
    func_002DEA68(a);
    v = a;
    func_002DE880(0x50, D_0048C450, -1, D_00598400, 2, &v);
    return 0;
}
