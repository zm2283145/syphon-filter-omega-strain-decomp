extern int func_0034CC60(int a, int b, int c, int *out, int *err);
int func_0034C3D8(void *cd, void *buf, int a, int b, int c)
{
    int out = 0;
    int err = -0x1F5;
    if (cd == 0) return -0x1F5;
    if (func_0034CC60(a, b, c, &out, &err) == 0) return out;
    return err ? err : -0x1F5;
}