extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598530;
unsigned int D_00497D10[1] = { 0x0 };
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusAccountUpdateProfile(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    iTerminateString_void_2(a + 0x2C, 0x20);
    iTerminateString_void_2(a + 0x4C, 0x20);
    iTerminateString_void_2(a + 0x6C, 0x20);
    iTerminateString_void_2(a + 0x8C, 0x20);
    iTerminateString_void_2(a + 0xAC, 0x20);
    iTerminateString_void_2(a + 0xCC, 0x20);
    iTerminateString_void_2(a + 0xEC, 0x20);
    iTerminateString_void_2(a + 0x10C, 0x3);
    iTerminateString_void_2(a + 0x10F, 0x20);
    iTerminateString_void_2(a + 0x12F, 0x20);
    iTerminateString_void_2(a + 0x14F, 0x10);
    iTerminateString_void_2(a + 0x15F, 0x50);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D10) = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_00598530, 0x1B0, a) ? -5 : 0;
}
