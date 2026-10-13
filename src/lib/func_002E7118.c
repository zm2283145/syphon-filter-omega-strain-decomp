typedef void (*Cb2E7118)(int, void *, int, int, int, int);
typedef struct {
    int f0;
    unsigned short f4;
    int f8;
    Cb2E7118 fC;
    int f10;
    int f14;
    int f18;
} E2E7118;
typedef struct { int f0; unsigned char b4; unsigned char b5; } P2E7118;
typedef struct { int w0; unsigned char b4; unsigned char b5; char pad[10]; } M2E7118;
extern E2E7118 D_0058D188[];
extern unsigned short D_0058D178;
extern char D_005880A0[];
extern unsigned int D_005983DC;
extern int func_002E52D8(unsigned int, int, void **);
extern int func_002DDB08(void *);
extern int func_002DDAC8(int *);
extern int func_002DD440(void *, void *);
extern int Net_SendTyped(signed char, int, int, int, unsigned int, int, void *);
int func_002E7118(unsigned int slot, int unused, int id, P2E7118 *p)
{
    M2E7118 m;
    char buf[16];
    void *q;
    int t;
    int dt;
    Cb2E7118 cb;
    if (p == 0) return -1;
    if ((signed char)p->b5 != 0) {
        if (slot >= 4) goto done;
        if (id == 0x100) goto done;
        q = 0;
        if (func_002E52D8(slot, id, &q) != 0) goto done;
        if (q == 0) goto done;
        if (*(unsigned char *)((char *)q + 0x28) != 1) goto done;
        func_002DDB08(&m);
        m.b4 = p->b4;
        m.b5 = 0;
        Net_SendTyped(-0x80, slot, id, 0, D_005983DC, 8, &m);
        goto done;
    }
    func_002DDAC8(&t);
    cb = D_0058D188[p->b4].fC;
    if (cb == 0) goto done;
    func_002DDAC8(&t);
    dt = t - D_0058D188[p->b4].f10;
    func_002DD440(buf, &D_0058D188[p->b4]);
    func_002DD440(D_005880A0, &D_0058D188[p->b4]);
    D_0058D178 = D_0058D188[p->b4].f4;
    if (D_0058D188[p->b4].f8 == 1)
        cb(0, buf, dt, p->f0, D_0058D188[p->b4].f14, D_0058D188[p->b4].f18);
    else
        ((void (*)(int, void *, int))cb)(0, buf, dt);
    D_0058D188[p->b4].fC = 0;
done:
    return 8;
}
