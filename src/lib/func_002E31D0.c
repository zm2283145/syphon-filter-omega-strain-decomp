typedef struct { unsigned char mask[0x24]; int n; int f28; } R;
typedef struct { unsigned char f0; unsigned char f1; unsigned short id; } H;
typedef struct { unsigned char f0; unsigned char f1; char pad[0x22]; int f24; int f28; } E;
typedef struct { int h; char data[1]; } M;
extern M D_0051F8D8;
extern unsigned int D_0048C450;
extern unsigned int D_005983F0;
extern int func_002DD968(E **, unsigned int);
extern void func_002E2DD0(R *, unsigned int);
extern unsigned char func_002E2F30(E *, unsigned int, unsigned char, unsigned char *, char *, int *);
extern int func_002DE5E8(signed char, unsigned int, unsigned int, unsigned int, int, void *, R *);
extern int func_002DE880(signed char, unsigned int, int, unsigned int, int, void *);

int func_002E31D0(unsigned int id, unsigned char type, unsigned char kind)
{
    H h;
    R r;
    unsigned char fl;
    E *e;
    int len;
    int ret;
    M *m;

    e = 0;
    len = 0;
    fl = 0;
    if (id >= 0x1000) return 0x17;
    ret = func_002DD968(&e, id);
    if (ret != 0) return ret;
    if (e == 0) return ret;
    if (e->f1 != 0) func_002E2DD0(&r, id);
    m = &D_0051F8D8;
    *(int *)&h = 0;
    h.id = id;
    h.f0 = e->f0;
    len = 4;
    h.f1 = func_002E2F30(e, id, kind, &fl, m->data, &len);
    m->h = *(int *)&h;
    e->f28 = 0;
    fl |= type;
    e->f24 = 0;
    if (h.f1 == 0) return 0;
    if (e->f1 != 0) func_002DE5E8(fl, D_0048C450, 0, D_005983F0, len, m, &r);
    else func_002DE880(fl, D_0048C450, -1, D_005983F0, len, m);
    return 0;
}


