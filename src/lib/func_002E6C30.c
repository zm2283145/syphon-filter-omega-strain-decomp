extern void func_002DB8E8(unsigned int, unsigned int);
int func_002E6C30(unsigned int a, int b, unsigned int c, int d)
{
    if (d == 0) return -1;
    if (a >= 4) return 1;
    if (c >= 0x100) return 1;
    func_002DB8E8(a, c);
    return 1;
}