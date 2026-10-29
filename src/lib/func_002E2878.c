typedef struct { char pad[0x400]; int cur; char pad404[0x444 - 0x404]; int max; } Ctx2E2878;
typedef struct { char pad[0xA]; unsigned short base; unsigned short cnt; } Grp2E2878;
typedef struct {
    unsigned char state; unsigned char b1; unsigned char b2; unsigned char b3;
    unsigned char b4; unsigned char b5; char pad6[2];
    int x8; int xC; int buf; int end; int cur; int x1C; int x20;
    unsigned short h24; unsigned short h26; int x28; char x2C[4];
} Ent2E2878;
extern unsigned int D_0048C450;
extern int D_0058DF78;
extern int NetGetConnInfo(unsigned int, Ctx2E2878 **);
extern int NetIGetClient(Grp2E2878 **, unsigned int, int);
extern int NetGetStreamChannel(int, Ent2E2878 **);
extern int DMEmalloc(int);
extern void DmeFree(int *);
extern int rt_circ_buf_create(void *, int, int);

int NetIOpenDataStream(int *out, int size, int a2, int a3, int t0, int t1, int t2, unsigned short t3, unsigned short st)
{
    Ctx2E2878 *ctx_[1];
#define ctx ctx_[0]
    Grp2E2878 *grp_[1];
#define grp grp_[0]
    Ent2E2878 *ent_[1];
#define ent ent_[0]
    int ret;
    int i;
    int id;

    grp = 0;
    ctx = 0;
    ent = 0;
    if (!out) return 0x17;
    *out = -1;
    if (size < 0) return 0x17;
    if (a2 < 0) return 0x17;
    if (D_0048C450 >= 4) return 0xF;
    if (a3 < 0 || a3 >= D_0058DF78) return 0x17;
    ret = NetGetConnInfo(D_0048C450, &ctx);
    if (ret) return ret;
    if (!ctx) return ret;
    if (ctx->cur < 0 || ctx->cur >= ctx->max) return 0x15;
    if (NetIGetClient(&grp, D_0048C450, ctx->cur) || !grp) return 0x15;
    if (grp->cnt == 0) return 0x14;
    for (i = 0; i < grp->cnt; i++) {
        id = i + grp->base;
        if (NetGetStreamChannel(id, &ent)) return 0x14;
        if (!ent) return 0x14;
        if (ent->state == 2) continue;
        ent->buf = DMEmalloc(size);
        if (!ent->buf) {
            ent->state = 0;
            return 0x16;
        }
        if (rt_circ_buf_create(ent->x2C, size, ent->buf)) {
            DmeFree(&ent->buf);
            ent->buf = 0;
            return 0x14;
        }
        ent->state = 2;
        ent->xC = ctx->cur;
        ent->x20 = a2;
        ent->b3 = a3;
        ent->b2 = t0;
        ent->x8 = t1;
        ent->b4 = 0;
        ent->h24 = t3;
        ent->h26 = st;
        ent->end = ent->buf + size;
        ent->cur = ent->buf;
        ent->x28 = 0;
        ent->x1C = 0;
        ent->b1 = t2;
        if (t1 == -1)
            ent->b5 = 1;
        else
            ent->b5 = 0;
        *out = id;
        return 0;
    }
    return 0x14;
}
