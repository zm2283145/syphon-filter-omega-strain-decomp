typedef struct { char pad[8]; int arg; char pad2[0x205C - 0xC]; int cb1; int cb2; char pad3[0x2A70 - 0x2064]; char buf[1]; } UpCtxE7C8;
typedef struct { char pad[4]; char host[0x20]; unsigned short port; unsigned short extPort; char pad2[0x50 - 0x28]; int state; char pad3[4]; UpCtxE7C8 *ctx; } UpnpE7C8;
extern char D_004B01B0[];
extern char D_004B02E0[];
extern int sprintf(char *buf, const char *fmt, ...);
extern int func_0030ECC0(UpnpE7C8 *u);
extern int func_0030C1B8(UpnpE7C8 *u, char *a, char *b);
extern int func_003060D8(void *p);
int UPnP_AddPortMapping(UpnpE7C8 *u, int arg, int unused, int cb)
{
    int r;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    u->ctx->arg = arg;
    sprintf(u->ctx->buf, D_004B01B0, u->extPort, u->port, u->host);
    r = func_0030C1B8(u, D_004B02E0, u->ctx->buf);
    if (r == 0) {
        u->state = 7;
        func_003060D8((char *)u->ctx + 0x10);
        u->ctx->cb1 = cb;
    }
    return r;
}
