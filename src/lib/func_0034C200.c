typedef struct { void *a; void *b; int n; int z; } NetReq_200;
typedef struct { int avail; int f4; int f8; int fC; char pad[0xC]; char *base; void *f20; int pos; } NetCtx_200;
typedef struct { char pad[0x20]; NetCtx_200 *ctx; } NetObj_200;
extern char D_004BA7D0[];
extern void func_0010D3E0(int a);
extern int func_0010D520(NetReq_200 *req, int n);
extern int func_0010D500(int h);
extern void func_00127358(const char *s);
extern void *memcpy(void *d, const void *s, unsigned int n);
extern int func_0034C8E0(NetObj_200 *o, int *out);
int func_0034C200(void *cd, int *buf, NetObj_200 *o, void *dst, int len, int *out)
{
    NetCtx_200 *c;
    NetReq_200 req;
    int l = 0;
    int r;
    int n;
    int h;
    if (o == 0) return -0x200;
    c = o->ctx;
    func_0010D3E0(0);
    if (c->fC != 0) {
        r = func_0034C8E0(o, &l);
        if (r != 0) return r;
        if (l == 0) return 0;
    }
    *out = c->f4;
    if (c->avail <= 0) return c->avail;
    n = len;
    if (c->avail < n) n = c->avail;
    memcpy(dst, c->base + c->pos, n);
    c->avail -= n;
    if (c->avail != 0) {
        c->pos += n;
    } else {
        c->pos = 0;
        func_0010D3E0(0);
        req.b = c->f20; req.a = c; req.n = 4; req.z = 0;
        h = func_0010D520(&req, 1);
        if (h == 0) func_00127358(D_004BA7D0);
        while (func_0010D500(h) >= 0) ;
    }
    return n;
}