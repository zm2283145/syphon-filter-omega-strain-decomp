typedef struct { char pad[0x18]; int f18; } P;
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00497CE8;
extern int D_00497CEC;
extern int D_00497CE4;
int D_00497DE4 = 0;
int D_00497DE8 = 0;
extern int D_005988D4;
extern int iTerminateString_void_2(P *, int);
extern int NetSendMessage(int, int, int, int, int, int, P *);
int MediusGetUniverseInformation(P *p, int b, int c)
{
    iTerminateString_void_2(p, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497CE8 = 0;
    D_00497CE4 = p->f18;
    D_00497CEC = D_00497CC0;
    D_00497DE4 = b;
    D_00497DE8 = c;
    if (NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_005988D4, 0x24, p)) return -5;
    return 0;
}
