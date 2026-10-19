extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598780;
unsigned int D_00497DC0[1] = { 0x0 };
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00469990(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0x40);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DC0) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598780, 0x6C, a) ? -5 : 0;
}
