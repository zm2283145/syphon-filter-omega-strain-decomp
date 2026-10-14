typedef struct { char pad[0xC]; int busy; char pad2[0x206C - 0x10]; void *cb; } UpCtxEBF0;
typedef struct { char pad[0x28]; char name[0x10]; unsigned short port; char pad2[0x50 - 0x3A]; int state; char pad3[4]; UpCtxEBF0 *ctx; int pad4; int user; } UpnpEBF0;
extern int func_0030ECC0(UpnpEBF0 *u);
extern int func_0030DF28(UpnpEBF0 *u, int size, void (*cb)());
extern void func_0030DB38();
extern char *strncpy(char *d, const char *s, unsigned int n);
int func_0030EBF0(UpnpEBF0 *u, const char *name, unsigned short port, void *cb, int user)
{
    int r;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (func_0030ECC0(u) != 0) return 3;
    r = func_0030DF28(u, 0x1000, func_0030DB38);
    if (r == 0) {
        u->user = user;
        u->ctx->cb = cb;
        u->ctx->busy = 1;
        u->port = port;
        strncpy(u->name, name, 0x10);
    }
    return r;
}
