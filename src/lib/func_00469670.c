extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598530;
extern int D_00497D10;
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00469670(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    func_004700F8(a + 0x2C, 0x20);
    func_004700F8(a + 0x4C, 0x20);
    func_004700F8(a + 0x6C, 0x20);
    func_004700F8(a + 0x8C, 0x20);
    func_004700F8(a + 0xAC, 0x20);
    func_004700F8(a + 0xCC, 0x20);
    func_004700F8(a + 0xEC, 0x20);
    func_004700F8(a + 0x10C, 0x3);
    func_004700F8(a + 0x10F, 0x20);
    func_004700F8(a + 0x12F, 0x20);
    func_004700F8(a + 0x14F, 0x10);
    func_004700F8(a + 0x15F, 0x50);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D10 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598530, 0x1B0, a) ? -5 : 0;
}
