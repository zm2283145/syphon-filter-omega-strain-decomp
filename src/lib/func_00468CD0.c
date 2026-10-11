extern short D_00497CC0;
extern int D_00497CC4;
extern int func_002EC738(int);
int func_00468CD0(void)
{
    int r;
    if (D_00497CC0 != 1) return -0xF;
    {
        int *pc = &D_00497CC4;
        if (*pc < 0) return -0x10;
        r = func_002EC738(*pc);
        *pc = -1;
    }
    return r ? -3 : 0;
}