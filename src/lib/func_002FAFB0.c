int func_002FAFB0(unsigned int *o, unsigned int *out)
{
    if (out == 0) return 2;
    if (o[0] < o[1]) *out = o[2] - o[1];
    else if (o[1] < o[0]) *out = o[0] - o[1];
    else *out = 0;
    return 0;
}