extern int D_00497CC0;
extern int D_00497CC4;
extern int D_005986C8;
extern int D_00598458;
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00467138(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598458 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986C8, 0x2C, a) ? -5 : 0;
}