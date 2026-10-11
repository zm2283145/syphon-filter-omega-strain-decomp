extern int func_002DD968(int **, unsigned int);
extern void func_002DE950(int, unsigned int, int);
int func_002E7608(int a, int b, int c, unsigned char *k)
{
    int *p;
    unsigned char v;
    if (k == 0) return -1;
    v = k[0];
    func_002DD968(&p, *(unsigned short *)(k + 2));
    if (p) {
        p[1] = v;
        func_002DE950(p[1], *(unsigned short *)(k + 2), -2);
    }
    return 4;
}