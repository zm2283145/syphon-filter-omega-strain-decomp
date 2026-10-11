extern int func_00301710(unsigned short id, int *out);
int func_00301758(unsigned short id, unsigned char *out)
{
    int l = 0;
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    ret = func_00301710(id, &l);
    if (ret != 0) return ret;
    if (l != 0) *out = 1;
    return ret;
}