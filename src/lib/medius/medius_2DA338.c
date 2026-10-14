extern int func_002D9E18(char *, int);
extern int func_002EF200(int);
int func_002DA338(char *o)
{
    int r = 0;
    int n = *(int *)(o + 0x98);
    if (n > 0) {
        r = func_002D9E18(o, n);
        if (r && *(int *)(o + 0x60) == 0) {
            if (func_002EF200(r)) r = 0;
        }
    }
    return r;
}