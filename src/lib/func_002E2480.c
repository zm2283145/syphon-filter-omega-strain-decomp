typedef struct { char pad0[0x400]; int x400; char pad404[0x40]; int x444; } Ctx;
typedef struct { char pad0[6]; unsigned short base; unsigned short n; } Q;
typedef struct { int f0; int f4; char pad8[0x220]; } Ent;
typedef struct {
    unsigned char b0; unsigned char b1; unsigned char b2; unsigned char b3;
    int f4; int f8; char name[0xF]; char z1B;
    void *f1C; void *f20; char pad24[8]; int f2C; int f30; int f34; void *f38; void *f3C;
    char pad40[4];
} P;
extern unsigned int D_0048C450;
extern int D_0048C464;
extern int D_0058806C;
extern P *D_005880B0[];
extern signed char D_0058C178[];
extern Ent D_0058DF98[];
extern int NetGetConnInfo(unsigned int, Ctx **);
extern int NetIGetClient(Q **, unsigned int, int);
extern void *DMEmalloc(int);
extern void DmeFree(void *);
extern char *strncpy(char *, const char *, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);

int NetICreateObject(int *out, int mode, int a2, int a3, int t0, int t1, int t2, void *t3, char *name, unsigned int idx)
{
    Ctx *ctx;
    Q *q;
    P *p;
    P *np;
    int r;
    int i;
    unsigned int s;
    int sz;
    signed char old;
    int saved;
    int v;
    Ctx *c;
    Ent *e;

    p = 0;
    q = 0;
    ctx = 0;
    if (out == 0) return 0x17;
    *out = -1;
    if (name == 0) return 0x17;
    if (idx >= 0x10) return 0x17;
    if (D_0048C450 >= 4) return 0xF;
    r = NetGetConnInfo(D_0048C450, &ctx);
    if (r != 0) return r;
    if (ctx == 0) return r;
    if (ctx->x400 < 0 || ctx->x400 >= ctx->x444) return 0x15;
    NetIGetClient(&q, D_0048C450, ctx->x400);
    if (q == 0) return 0x15;
    if (q->n == 0) return 0x13;
    e = &D_0058DF98[idx];
    if (e == 0) return 0x17;
    for (i = 0; i < q->n; i++) {
        s = i + q->base;
        if (s < 0x1000 && (old = D_0058C178[s]) != 2) {
            sz = D_0058DF98[idx].f0;
            saved = D_0048C464;
            np = DMEmalloc(0x44);
            p = np;
            if (np == 0) return 0x16;
            D_005880B0[s] = np;
            D_0058C178[s] = 2;
            if (D_0048C464 < (int)(s + 1)) D_0048C464 = s + 1;
            c = ctx;
            if (mode == 2) np->f4 = -1; else np->f4 = c->x400;
            np->f8 = c->x400;
            np->b2 = a2;
            p->b3 = t2;
            p->b1 = t0;
            p->f2C = D_0058806C + a3;
            p->f1C = DMEmalloc(sz);
            { void *t = DMEmalloc(sz); int n = ctx->x444; p->f20 = t; p->f38 = DMEmalloc(n * 4); }
            { void *x = DMEmalloc(e->f4 * 4); P *pp = p; pp->f3C = x; if (pp->f1C == 0) goto f1; if (p->f20 == 0 || p->f38 == 0 || x == 0) {
                if (p->f1C != 0) { DmeFree(&p->f1C); p->f1C = 0; }
              f1:
                if (p->f20 != 0) { DmeFree(&p->f20); p->f20 = 0; }
                if (p->f38 != 0) { DmeFree(&p->f38); p->f38 = 0; }
                if (p->f3C != 0) { DmeFree(&p->f3C); p->f3C = 0; }
                DmeFree(&p);
                D_0048C464 = saved;
                D_005880B0[s] = 0;
                D_0058C178[s] = old;
                return 0x16;
            } }
            strncpy(p->name, name, 0xF);
            p->z1B = 0;
            p->b0 = idx;
            { P *pp = p; pp->f34 = 0; pp->f30 = t1; if (t3 != 0) memcpy(pp->f1C, t3, sz); }
            *out = s;
            return 0;
        }
    }
    return 0x13;
}
