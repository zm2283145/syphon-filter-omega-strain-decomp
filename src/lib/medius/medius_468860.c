extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598668;
unsigned int D_00497D98[1] = { 0x0 };
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusVersionServer(char *a, int b)
{

    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D98) = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_00598668, 0x26, a) ? -5 : 0;
}
