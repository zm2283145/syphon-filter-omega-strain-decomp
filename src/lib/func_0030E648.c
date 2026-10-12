typedef struct { char pad[8]; int arg; char pad2[0x2050 - 0xC]; int cb2; int cb; } UpCtxE588;
typedef struct { char pad[0x50]; int state; char pad2[4]; UpCtxE588 *ctx; } UpnpE588;
extern char D_004AFFF0[];
extern char D_004AFF28[];
extern int func_0030ECC0(UpnpE588 *u);
extern int func_0030C1B8(UpnpE588 *u, char *a, char *b);
extern int func_003060D8(void *p);
int UPnP_GetExternalIPAddress(UpnpE588 *u, int arg, int cb)
{
    int r;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    r = func_0030C1B8(u, D_004AFFF0, D_004AFF28);
    if (r == 0) {
        u->state = 5;
        func_003060D8((char *)u->ctx + 0x10);
        u->ctx->cb = cb;
        u->ctx->arg = arg;
    }
    return r;
}
