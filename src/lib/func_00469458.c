extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598520;
int D_00497D0C = 0;
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00469458(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    func_004700F8(a + 0x2C, 0x20);
    func_004700F8(a + 0x4C, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D0C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598520, 0x6C, a) ? -5 : 0;
}
