extern short D_00497CC0;
extern int D_00497CC4;
extern int D_005984E4;

extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046A998(char *a)
{
    func_004700F8(a, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005984E4, 0x118, a) ? -5 : 0;
}
