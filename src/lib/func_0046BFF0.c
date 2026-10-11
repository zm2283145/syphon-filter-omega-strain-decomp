typedef struct { char pad[0x18]; int f18; } P;
extern short D_00497CC0;
extern int D_00497CC4, D_00497CE8, D_00497CEC, D_00497CE4, D_00497DE4, D_00497DE8, D_005988D4;
extern int func_004700F8(P *, int);
extern int Net_SendLocked(int, int, int, int, int, int, P *);
int func_0046BFF0(P *p, int b, int c)
{
    func_004700F8(p, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497CE8 = 0;
    D_00497CE4 = p->f18;
    D_00497CEC = D_00497CC0;
    D_00497DE4 = b;
    D_00497DE8 = c;
    if (Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005988D4, 0x24, p)) return -5;
    return 0;
}
