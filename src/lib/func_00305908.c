extern int D_004912F4, D_004912F0, D_004912EC, D_004912F8;
extern unsigned char D_004912E8;
extern int func_002FB3C0(int *pp);
int func_00305908(void)
{
    if (D_004912F4) func_002FB3C0(&D_004912F4);
    if (D_004912F0) func_002FB3C0(&D_004912F0);
    if (D_004912EC) func_002FB3C0(&D_004912EC);
    if (D_004912F8) func_002FB3C0(&D_004912F8);
    D_004912E8 = 0;
    return 0;
}