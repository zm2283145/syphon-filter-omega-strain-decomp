extern int func_00311188(int h);
int func_00310CC0(int* h, unsigned char* out)
{
    int ret = 5;
    if (h == 0) return ret;
    if (out == 0) return ret;
    *out = func_00311188(*h);
    return 0;
}
