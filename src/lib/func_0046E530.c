extern int D_00497CE8;
extern void (*D_00497DE8)(void);
int func_0046E530(int a0, int a1, int a2, signed char* p)
{
    if (p[0x22C] == 1)
        D_00497CE8 |= 1;
    if (D_00497DE8)
        D_00497DE8();
    return 0x230;
}
