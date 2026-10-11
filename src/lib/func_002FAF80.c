int func_002FAF80(int *o, int *out)
{
    int d;
    if (out == 0) return 2;
    d = o[2] - o[3];
    if (d < 0) d = 0;
    *out = d;
    return 0;
}