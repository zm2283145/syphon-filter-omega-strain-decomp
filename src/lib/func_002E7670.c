extern int func_002DD968(int **, unsigned int);
extern void func_002DE950(int, unsigned int, int);
int func_002E7670(int a, int b, int c, unsigned short *k)
{
    int *p;
    if (k == 0) return -1;
    func_002DD968(&p, *k);
    if (p == 0) return 2;
    p[1] = -1;
    func_002DE950(p[1], *k, -2);
    return 2;
}