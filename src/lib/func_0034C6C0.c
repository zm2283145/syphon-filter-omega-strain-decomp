typedef struct { int err; int f4; int f8; int fC; char pad[0x14]; int f24; char pad2[0xC]; int state; } NetCtx_6C0;
typedef struct { char pad[0x20]; NetCtx_6C0 *ctx; } NetObj_6C0;
extern void FlushCache(int a);
extern int libnetb_get_valid_data_header_ptr(NetCtx_6C0 *c, NetCtx_6C0 **pp, unsigned char *flag);
extern int sceBInetIsOpened(NetObj_6C0 *o, int *out);
int sceBInetGetAvailBytesToRead(NetObj_6C0 *o, int *out)
{
    NetCtx_6C0 *c;
    int r;
    int l;
    if (o == 0 || out == 0) return -0x200;
    c = o->ctx;
    FlushCache(0);
    if (c->state == 0 || c->state == 3) {
        unsigned char flag;
        NetCtx_6C0 *p;
        flag = 0;
        p = 0;
        r = libnetb_get_valid_data_header_ptr(c, &p, &flag);
        if (r != 0) return r;
        if (flag == 1) { *out = p->f24; return p->fC; }
        *out = 0;
        return 0;
    }
    l = 0;
    if (c->fC != 0) {
        r = sceBInetIsOpened(o, &l);
        if (r != 0) return r;
        if (l == 0) return 0;
    }
    if (c->err == 0) { *out = c->f4; return 0; }
    return c->err;
}