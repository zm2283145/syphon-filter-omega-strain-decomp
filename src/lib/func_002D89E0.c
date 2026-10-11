extern int func_002D8708(int, char *, int);
extern void func_002DA290(int, char *, int);
void func_002D89E0(int a)
{
    char buf[0x7E00];
    int n = func_002D8708(a, buf, 0x7E00);
    if (n > 0) func_002DA290(a, buf, n);
}