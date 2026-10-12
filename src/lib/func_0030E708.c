typedef struct { char pad[8]; int arg; char pad2[0x2058 - 0xC]; int cb; } UpCtxE708;
typedef struct { char pad[0x50]; int state; char pad2[4]; UpCtxE708 *ctx; } UpnpE708;
extern char D_004B0190[];
extern int func_0030ECC0(UpnpE708 *u);
extern int func_0030BFE8(UpnpE708 *u, int arg, char *b);
extern int func_003060D8(void *p);
int UPnP_GetPortMappingNumberOfEntries(UpnpE708 *u, int arg, int cb)
{
    int r;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    r = func_0030BFE8(u, arg, D_004B0190);
    if (r == 0) {
        u->state = 6;
        func_003060D8((char *)u->ctx + 0x10);
        u->ctx->cb = cb;
        u->ctx->arg = arg;
    }
    return r;
}
