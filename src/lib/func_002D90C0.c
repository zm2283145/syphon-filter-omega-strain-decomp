extern void func_002DA4E0(char *, int);
extern void func_002EF500(int);
void func_002D90C0(char *o)
{
    int n = *(int *)(o + 0x98);
    if (n > 0) func_002DA4E0(o, n);
    if (*(int *)(o + 0x64)) func_002EF500(*(int *)(o + 0x64));
    *(int *)(o + 0x70) &= ~2;
}