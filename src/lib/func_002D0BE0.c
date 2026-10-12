extern short D_0048C414;
extern int D_0048C3D8;
extern int D_0048C3CC;
extern int func_002D0EB8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_002D0BE0(char *a)
{
    func_002D0EB8(a, 0x15);
    func_002D0EB8(a + 0x15, 0x40);
    func_002D0EB8(a + 0x155, 0x20);
    func_002D0EB8(a + 0x55, 0x100);
    if (D_0048C414 != 1) return -0xC;
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3CC, 0x1A8, a) ? -5 : 0;
}
