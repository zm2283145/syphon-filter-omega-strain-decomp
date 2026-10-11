extern int func_002E51B8(unsigned int, unsigned char ***);
int func_002DDC00(int *out, unsigned int idx)
{
    unsigned char **p = 0;
    unsigned int i = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (idx >= 4) return 0x17;
    r = func_002E51B8(idx, &p);
    if (r) return r;
    if (p == 0) return r;
    for (; i < 0x100; i++) {
        if (p[i] && p[i][0x28] == 1) (*out)++;
    }
    return 0;
}
