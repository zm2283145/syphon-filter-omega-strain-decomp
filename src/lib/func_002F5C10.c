extern int D_0049089C;
extern int func_002F7B60(void);
int func_002F5C10(void)
{
    int r;
    if (D_0049089C <= 0) return 4;
    if (--D_0049089C == 0 && (r = func_002F7B60()) != 0) return r;
    return 0;
}
