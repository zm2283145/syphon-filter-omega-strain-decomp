extern short D_0048C414;
extern int D_0048C3D8;
extern int func_002D0EB8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
extern int D_0048C394;
extern int D_0048C3E4;
int func_002CF2C0(char *a, int b)
{
    func_002D0EB8(a, 0x15);
    if (D_0048C414 != 1) return -0xC;
    D_0048C3E4 = b;
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C394, 0x15, a) ? -5 : 0;
}
