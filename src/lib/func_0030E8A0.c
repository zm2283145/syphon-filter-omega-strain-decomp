typedef struct { char pad[8]; int arg; char pad2[0x2060 - 0xC]; int cb; char pad3[0x2A70 - 0x2064]; char buf[1]; } UpCtxE8A0;
typedef struct { char pad[0x24]; unsigned short port; unsigned short extPort; char pad2[0x50 - 0x28]; int state; char pad3[4]; UpCtxE8A0 *ctx; } UpnpE8A0;
extern char D_004B02F0[];
extern char D_004B0358[];
extern int sprintf(char *buf, const char *fmt, ...);
extern int func_0030ECC0(UpnpE8A0 *u);
extern int func_0030C1B8(UpnpE8A0 *u, char *a, char *b);
extern int func_003060D8(void *p);
int UPnP_GetSpecificPortMappingEntry(UpnpE8A0 *u, int arg, int cb)
{
    int r;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    u->ctx->arg = arg;
    sprintf(u->ctx->buf, D_004B02F0, u->extPort);
    r = func_0030C1B8(u, D_004B0358, u->ctx->buf);
    if (r == 0) {
        u->state = 8;
        func_003060D8((char *)u->ctx + 0x10);
        u->ctx->cb = cb;
    }
    return r;
}
