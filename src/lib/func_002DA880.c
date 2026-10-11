extern int func_002D9E18(int, int);
extern int func_002EF5B0(int, int, int);
int func_002DA880(int a, int b, int c, int d)
{
    int h = func_002D9E18(a, d);
    if (b == 0 || h == 0) return -1;
    return func_002EF5B0(h, b, c);
}