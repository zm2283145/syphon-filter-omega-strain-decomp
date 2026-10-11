extern void func_002D9E18(char *, int);
extern int func_002DA338(char *);
int func_002DACB0(char *o)
{
    int n = *(int *)(o + 0x98);
    if (n > 0) func_002D9E18(o, n);
    if (func_002DA338(o)) *(int *)(o + 0x70) |= 8;
    else *(int *)(o + 0x70) &= ~8;
    return *(int *)(o + 0x70);
}