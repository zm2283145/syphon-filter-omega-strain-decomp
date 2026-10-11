extern int func_002FAF18(char *);
extern int func_002FAF00(int);
int func_002FAC20(char *o, int *out)
{
    int v;
    if (func_002FAF18(o) == 0) return 2;
    *out = *(int *)(o + 0x14);
    while ((v = func_002FAF00(*out)) != 0) *out = func_002FAF00(*out);
    return 0;
}