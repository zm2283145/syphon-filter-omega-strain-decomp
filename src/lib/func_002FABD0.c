extern int func_002FAF18(char *);
int func_002FABD0(char *o, int *out)
{
    if (func_002FAF18(o) == 0) return 2;
    *out = *(int *)(o + 0x14);
    return 0;
}