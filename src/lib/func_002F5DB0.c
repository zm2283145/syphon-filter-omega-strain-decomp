extern int func_002F6770(int, char **);
extern void func_002F7B90(int);
extern int func_002F6728(int);
int func_002F5DB0(int a)
{
    char *p = 0;
    int r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    func_002F7B90(*(int *)(p + 4));
    p[1] = 0;
    p[0] = 0;
    return func_002F6728(a);
}