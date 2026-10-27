extern short D_00497CC0;
extern int D_00497CC4;
extern int D_0059855C;
unsigned int D_00497D30[1] = { 0x0 };
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusCreateGame(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    iTerminateString_void_2(a + 0x38, 0x40);
    iTerminateString_void_2(a + 0x78, 0x20);
    iTerminateString_void_2(a + 0x98, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D30) = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_0059855C, 0xD0, a) ? -5 : 0;
}
