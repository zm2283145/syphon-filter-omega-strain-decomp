extern unsigned int D_0048C450;
extern int func_002E51B8(unsigned int, char **);
extern void func_002DB188(char **, unsigned int, int);
extern int func_002DD968(char **, unsigned int);
extern void func_002DB550(unsigned int, int);
int func_002DB820(unsigned int id)
{
    char *p = 0;
    char *q;
    char *e;
    int r;
    if (D_0048C450 >= 4) return 8;
    if (id >= 0x1000) return 0x17;
    r = func_002E51B8(D_0048C450, &p);
    if (r) return r;
    func_002DB188(&q, D_0048C450, *(int *)(p + 0x400));
    if (q == 0) return 0x15;
    func_002DD968(&e, id);
    if (e == 0) return 0x1E;
    if (*(int *)(e + 4) != *(int *)(p + 0x400)) return 8;
    ((struct { int a; unsigned short id; } *)q)->id = id;
    func_002DB550(D_0048C450, -1);
    return 0;
}
