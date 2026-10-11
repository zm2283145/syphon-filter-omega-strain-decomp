extern void (*D_004908E4)(int);
extern void func_001253C0(int);
int func_002FB3C0(int *p)
{
    if (*p) {
        if (D_004908E4 == 0) func_001253C0(*p);
        else D_004908E4(*p);
        *p = 0;
    }
    return 0;
}