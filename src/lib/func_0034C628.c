extern int func_0034CF00(int a, unsigned short b, int c, int *out, int *err);
int func_0034C628(void *cd, void *buf, int a, unsigned short b, int c)
{
    int out = 0;
    int err = -0x1F5;
    if (cd == 0) return -0x1F5;
    if (func_0034CF00(a, b, c, &out, &err) == 0) return out;
    return err ? err : -0x1F5;
}