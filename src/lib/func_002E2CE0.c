extern unsigned int D_0048C450;
extern int D_00598408;
extern int func_002E51B8(unsigned int, char **);
extern int func_002DD968(char **, unsigned int);
extern int func_002DE950(int, unsigned int, int);
extern int func_002E31D0(unsigned int, int, int);
extern int func_002DE880(int, unsigned int, int, int, int, void *);

int func_002E2CE0(unsigned int id)
{
    struct { short id; } msg;
    char *q;
    char *p;
    int r;

    q = 0;
    p = 0;
    if (id >= 0x1000) return 0x17;
    if (D_0048C450 >= 4) return 8;
    r = func_002E51B8(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return 0;
    func_002DD968(&q, id);
    if (q == 0) return 8;
    if (*(int *)(q + 4) == *(int *)(p + 0x400)) {
        *(int *)(q + 4) = -1;
        func_002DE950(*(int *)(q + 4), id, -2);
        msg.id = id;
        func_002E31D0(id, 0x50, 1);
        func_002DE880(0x50, D_0048C450, -1, D_00598408, 2, &msg);
        return 0;
    }
    return 8;
}
