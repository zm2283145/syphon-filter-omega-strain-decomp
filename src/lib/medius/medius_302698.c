typedef struct { unsigned short f0; char pad[2]; unsigned int max; unsigned int f8; int fC; int f10; int f14; int f18; int f1C; void *f20; void *f24; void *f28; void *f2C; void *f30; void *f34; } Cfg;
typedef struct { int a; int b; int c; } E;
typedef struct { int f0; int f4; int f8; char pad[0x1C]; } T;
typedef struct {
    E e[32];
    int h;
    T *tbl;
    unsigned int max;
    unsigned int f18C;
    char f190[0xC];
    int f19C;
    int f1A0;
    int f1A4;
    int f1A8;
    int f1AC;
    int f1B0;
    int f1B4;
} O;
typedef struct { unsigned short f0; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; void *f20; O *f24; } P;
extern int rt_memory_allocate_init_zero(void *, int);
extern void *memset(void *, int, unsigned int);
extern int rt_udp_event_cb();
extern int func_002FB2D8(void *, unsigned long long);
extern int rt_udp_create(int *, P *);
extern void KM_Initialize(int, int);
extern void KM_Create(int, int, int);
int rt_p2p_create(Cfg *cfg, O **out)
{
    P p;
    O *o;
    unsigned int i;
    int r, r2, r3, r4;
    o = 0;
    if (cfg == 0) return 2;
    if (out == 0) return 2;
    if (cfg->max > 0x100) return 2;
    r = rt_memory_allocate_init_zero(&o, 0x1B8);
    if (o == 0) return 3; if (r != 0) return 3;
    for (i = 0; i < 32; i++) o->e[i].a = -1;
    *out = o;
    o->max = cfg->max;
    o->f18C = cfg->f8;
    o->f19C = (int)cfg->f20;

    o->f1A0 = (int)cfg->f24;
    o->f1A4 = (int)cfg->f28;
    o->f1A8 = (int)cfg->f2C;
    o->f1AC = (int)cfg->f30;
    o->f1B4 = (int)cfg->f34;

    memset(&p, 0, 0x28);
    p.f0 = cfg->f0;
    p.f4 = 0;
    p.f8 = 0x100;
    p.fC = cfg->f8;
    p.f10 = cfg->fC;
    p.f14 = cfg->f10;
    p.f18 = cfg->f14;
    p.f1C = cfg->f18;
    p.f20 = rt_udp_event_cb;
    p.f24 = o;
    r2 = rt_memory_allocate_init_zero(&o->tbl, 0x2800);
    if (o == 0) return 3; if (r2 != 0) return 3;
    for (i = 0; i < 256; i++) {
        o->tbl[i].f4 = -1;
        o->tbl[i].f8 = -1;
    }
    r3 = func_002FB2D8(o->f190, o->f18C);
    if (o == 0) return 3; if (r3 != 0) return 3;
    r4 = rt_udp_create(&o->h, &p);
    if (o->h == 0) return 4; if (r4 != 0) return 4;
    KM_Initialize(-1, cfg->f1C);
    KM_Create(-1, 0, 0);
    return 0;
}
