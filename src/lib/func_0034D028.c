extern int func_002FB518(char *);
int func_0034D028(char *p)
{
    if (p == 0) return 2;
    if (func_002FB518(p + 0x10)) return 1;
    return func_002FB518(p + 0x18) != 0;
}