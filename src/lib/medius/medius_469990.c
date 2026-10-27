extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598780;
unsigned int D_00497DC0[1] = { 0x0 };
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusTextFilter(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    iTerminateString_void_2(a + 0x2C, 0x40);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DC0) = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_00598780, 0x6C, a) ? -5 : 0;
}
