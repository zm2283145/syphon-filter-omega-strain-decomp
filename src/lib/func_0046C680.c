extern short D_00497CC0;
extern int D_00497CC4;
extern int D_0059881C;
extern int D_00497E14;
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046C680(char *a, int b)
{
    func_004700F8(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497E14 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059881C, 0x1C, a) ? -5 : 0;
}
