extern int D_00497CE8;
extern void (*D_00497DE4)(void);
int func_0046E4D8(int a0, int a1, int a2, signed char* p)
{
    if (p[0x11C] == 1)
        D_00497CE8 |= 2;
    if (D_00497DE4)
        D_00497DE4();
    return 0x120;
}
