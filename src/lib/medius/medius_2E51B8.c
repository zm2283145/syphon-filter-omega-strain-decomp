extern int D_0051FED8[];
int NetGetConnInfo(unsigned int i, int* out)
{
    if (out == 0)
        return 0x17;
    *out = 0;
    if (i >= 4)
        return 0xF;
    *out = D_0051FED8[i];
    return 0;
}
