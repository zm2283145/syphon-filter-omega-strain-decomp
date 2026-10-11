extern int Net_AllocZeroed(char **, int);
int func_002F66B8(char **out)
{
    char *p = 0;
    if (out == 0) return 2;
    *out = 0;
    if (Net_AllocZeroed(&p, 0x18)) return 9;
    if (p == 0) return 0xA;
    *p = 1;
    *out = p;
    return 0;
}