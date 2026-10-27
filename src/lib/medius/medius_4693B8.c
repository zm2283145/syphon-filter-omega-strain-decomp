extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598528;
int D_00497D1C = 0;
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusAccountGetProfile(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D1C = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_00598528, 0x26, a) ? -5 : 0;
}