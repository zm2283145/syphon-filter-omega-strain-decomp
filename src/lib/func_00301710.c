extern int func_002F9780(int id, int mask, int a, int b);
int func_00301710(unsigned short id, int *out)
{
    int ret = 2;
    if (out == 0) return ret;
    *out = func_002F9780(id, 0xFFFF, 0, 0);
    return 0;
}