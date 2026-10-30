typedef void *P;
/* distinct pointer types = distinct alias sets under -fstrict-aliasing; they decide which s->x loads may pass o->y stores */
typedef struct TA *P1; typedef struct TB *P2; typedef struct TC *P3; typedef struct TD *P4;
typedef struct N2D8B38 { struct N2D8B38 *next; struct N2D8B38 *prev; } N2D8B38;
typedef struct {
    unsigned short f0; char pad2[2]; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; int f20; int f24;
    int f28; int f2C; P4 f30; P1 f34; P2 f38; P3 f3C;
} S2D8B38;
typedef struct {
    char pad0[0xC]; int fC; int f10; int f14; int f18; int f1C; int f20; int f24; char pad28[0x20];
    P4 f48; P1 f4C; P2 f50; P3 f54; char pad58[4]; P1 f5C; char pad60[4]; int f64; N2D8B38 *f68; N2D8B38 *f6C;
    int f70; int f74; int f78; int f7C; int f80; char pad84[8]; int f8C; char pad90[0xC]; int f9C; int fA0;
    int fA4; int fA8; int fAC; int fB0; int fB4; int fB8;
} O2D8B38;
typedef struct { unsigned short f0; char pad2[2]; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; void *f20; void *f24; } P2D8B38;
typedef struct { int f0; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; } Q2D8B38;
extern void AddGrid(O2D8B38 *, int, int);
extern P1 CreateResourceManager(O2D8B38 *, int);
extern int CreateColorArray(int, int);
extern void *memset(void *, int, unsigned int);
extern int rt_udp_create(int *, P2D8B38 *);
extern void rt_udp_get_local_address(int, char *, int *);
extern int rt_audio_stringtoip(char *);
extern N2D8B38 *CreatePlayerSpecific(O2D8B38 *, Q2D8B38 *);
extern void GridAddPlayer(int, N2D8B38 *);
extern void rt_audio_udp_event_callback(void);
int InitializeAudio(O2D8B38 *o, S2D8B38 *s)
{
    P2D8B38 p;
    Q2D8B38 q;
    char name[0x10];
    int r;
    N2D8B38 *n;
    if (o->f70 & 1) return 1;
    AddGrid(o, 0, 3);
    o->fC = s->f28;
    o->f48 = s->f30;
    o->f74 = s->f24;
    o->f10 = s->f8;
    o->f4C = s->f34;
    o->f50 = s->f38;
    o->f14 = s->f14;
    o->f54 = s->f3C;
    o->f20 = s->f4;
    o->f24 = s->f10;
    o->f18 = s->fC;
    o->f1C = s->f18;
    if (o->fC <= 0) o->fC = 1;
    o->f5C = CreateResourceManager(o, o->fC);
    o->f9C = s->f1C;
    o->fA0 = s->f20;
    if (o->f50) {
        o->fA4 = CreateColorArray(o->f9C, o->fA0);
        o->fA8 = CreateColorArray(o->f9C / 2, o->fA0 / 2);
        o->fAC = CreateColorArray(o->f9C / 2, o->fA0 / 2);
    }
    if (o->f54) {
        o->fB0 = CreateColorArray(o->f9C, o->fA0);
        o->fB4 = CreateColorArray(o->f9C / 2, o->fA0 / 2);
        o->fB8 = CreateColorArray(o->f9C / 2, o->fA0 / 2);
    }
    memset(&p, 0, sizeof(p));
    p.f0 = s->f0;
    p.f4 = 1;
    p.fC = 0x500;
    p.f8 = 0x100;
    p.f20 = rt_audio_udp_event_callback;
    p.f1C = s->f2C;
    p.f24 = o;
    p.f14 = 0x1000;
    p.f10 = 0x1000;
    for (;;) {
        r = rt_udp_create(&o->f8C, &p);
        if (r == 0) break;
        if (r == 0x11) {
            if (p.f4 == 1) { p.f4 = 2; continue; }
            if (p.f4 == 2) { p.f4 = 3; continue; }
            if (p.f4 == 3) { p.f4 = 4; continue; }
            break;
        }
        return -1;
    }
    name[0] = 0;
    rt_udp_get_local_address(o->f8C, name, &o->f80);
    o->f7C = rt_audio_stringtoip(name);
    memset(&q, 0, sizeof(q));
    q.f14 = o->f78;
    q.f4 = o->f7C;
    q.fC = o->f80;
    q.f18 = 0;
    n = CreatePlayerSpecific(o, &q);
    o->f68 = n;
    o->f6C = n;
    n->prev = n;
    o->f6C->next = o->f6C;
    GridAddPlayer(o->f64, o->f68);
    o->f70 |= 1;
    return 0;
}



