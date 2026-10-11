extern short D_0048C414;
extern int D_0048C3D8;
extern int func_002D0EB8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);extern int D_0048C3B0;
int func_002D0958(char *a)
{
    func_002D0EB8(a, 0x15);
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3B0, 0x16, a) ? -5 : 0;
}