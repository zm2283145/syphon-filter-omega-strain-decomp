extern int D_00497CE8;
extern void (*D_00497DF0)(void);
int func_0046E5B8(int a0, int a1, int a2, signed char* p)
{
    if (p[0x2B4] == 1)
        D_00497CE8 |= 1;
    if (D_00497DF0)
        D_00497DF0();
    return 0x338;
}
