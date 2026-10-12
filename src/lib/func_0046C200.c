extern short D_00497CC0;
extern int D_00497CC4;
extern int D_005987D4;
unsigned int D_00497DF8[1] = { 0x0 };
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046C200(char *a, int b)
{
    func_004700F8(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DF8) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987D4, 0x1C, a) ? -5 : 0;
}
