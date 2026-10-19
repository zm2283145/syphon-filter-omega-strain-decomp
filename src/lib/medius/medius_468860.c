extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598668;
unsigned int D_00497D98[1] = { 0x0 };
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00468860(char *a, int b)
{

    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D98) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598668, 0x26, a) ? -5 : 0;
}
