extern short D_0048C414;
extern int D_0048C3D8;
extern int func_002D0EB8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);extern int D_0048C3A8;
int func_002D08D8(char *a)
{
    func_002D0EB8(a, 0x15);
    func_002D0EB8(a + 0x16, 0x11);
    if (D_0048C414 != 1) return -0xC;
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3A8, 0x68, a) ? -5 : 0;
}