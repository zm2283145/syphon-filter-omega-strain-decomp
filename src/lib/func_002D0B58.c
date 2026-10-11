extern short D_0048C414;
extern int D_0048C3D8;
extern int func_002D0EB8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);extern int D_0048C3C4;
extern int D_0048C3FC;
int func_002D0B58(char *a, int b)
{
    int r;
    func_002D0EB8(a, 0x15);
    if (D_0048C414 != 1) return -0xC;
    r = Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3C4, 0x1C, a);
    D_0048C3FC = b;
    return r ? -5 : 0;
}