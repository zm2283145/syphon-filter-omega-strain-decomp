extern short D_00497CC0;
extern int D_00497CC4;
extern int D_005984E0;

extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046AA18(char *a)
{
    func_004700F8(a, 0x11);
    func_004700F8(a + 0x1C, 0x40);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005984E0, 0x180, a) ? -5 : 0;
}
