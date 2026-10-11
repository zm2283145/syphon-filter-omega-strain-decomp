extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598548;
extern int D_00497D20;
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_004697A0(char *a, int b)
{

    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D20 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598548, 0x46, a) ? -5 : 0;
}
