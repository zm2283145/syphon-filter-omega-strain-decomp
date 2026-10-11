extern short D_00497CC0;
extern int D_00497CC4;
extern int D_005985FC;

extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046A690(char *a)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x1C, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 0x4, D_005985FC, 0x38, a) ? -5 : 0;
}
