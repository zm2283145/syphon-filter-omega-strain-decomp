extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598820;
unsigned int D_00497E18[1] = { 0x0 };
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046C710(char *a, int b)
{
    func_004700F8(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497E18) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 0x4, D_00598820, 0x20, a) ? -5 : 0;
}
