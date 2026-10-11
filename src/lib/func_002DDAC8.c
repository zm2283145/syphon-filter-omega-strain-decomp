extern void func_00306018(int *);
int func_002DDAC8(int *p)
{
    int t[4];
    if (p == 0) return 0x17;
    func_00306018(t);
    *p = t[0];
    return 0;
}