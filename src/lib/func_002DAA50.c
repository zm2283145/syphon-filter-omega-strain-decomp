extern int func_002D9E18(char *, int);
extern void func_002EFB28(int);
int func_002DAA50(char *o, int v)
{
    if (*(int *)(o + 0x74) && v == 0) {
        int n = *(int *)(o + 0x98);
        if (n > 0) func_002EFB28(func_002D9E18(o, n));
    }
    *(int *)(o + 0x74) = v;
    return 0;
}