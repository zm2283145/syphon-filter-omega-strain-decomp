extern short D_00497CC0;
extern int D_00497CC4;
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);extern int D_005984F8;
int D_00497CFC = 0;
int func_004690A0(char *a, int b)
{
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    func_004700F8(a + 0x15, 0x11);
    func_004700F8(a, 0x15);
    D_00497CFC = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005984F8, 0x26, a) ? -5 : 0;
}