typedef struct { int f0; int f4; } Res;
extern unsigned char D_0048C4D7, D_0048C4DC;
extern unsigned int D_0048C4D8;
extern char D_005253F0[];
extern int func_003021D0(char *);
extern int func_00302218(char *);
extern int RecursiveLock_Acquire(char *, int);
extern int RecursiveLock_Release(char *, int);
extern int NetMsg_Init(int *, Res *);

int func_002E94E0(int *o, Res *res)
{
    int r;
    int v;

    if (res == 0) return 0x17;
    res->f4 = 0x12;
    res->f0 = 1;
    if (o == 0) {
        res->f4 = 0x17;
        return 0x17;
    }
    v = *o;
    if (v != 1) {
        res->f4 = 0x26;
        return 0x17;
    }
    if (D_0048C4D8 != 0) {
        D_0048C4D8++;
        res->f4 = 0;
        return 0;
    }
    if (D_0048C4DC == v || func_003021D0(D_005253F0) != 0) {
        res->f4 = 0x2B;
        return 0x2B;
    }
    D_0048C4DC = v;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = NetMsg_Init(o, res);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    if (r) {
        func_00302218(D_005253F0);
        D_0048C4DC = 0;
        D_0048C4D7 = 0;
        return r;
    }
    D_0048C4D8 = v;
    D_0048C4D7 = v;
    return 0;
}

