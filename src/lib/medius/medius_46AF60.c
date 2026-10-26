extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598660;
int D_00497D9C = 0;
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int MediusGetMyIP(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D9C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598660, 0x26, a) ? -5 : 0;
}