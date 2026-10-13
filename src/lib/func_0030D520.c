typedef struct Upnp Upnp;
typedef struct {
    int h0;
    int h4;
    int h8;
    char pad0c[0x1018];
    int status;
    char pad1028[0x103C];
    void (*cb)(Upnp *u, int r, int arg);
} UpnpCtx;
struct Upnp {
    char pad[0x50];
    int active;
    unsigned char started;
    char pad55[3];
    UpnpCtx *ctx;
};
extern int func_0030BC98(Upnp *u, unsigned char *flag);
extern int func_00310C30(int);
extern void func_002F5DB0(int);
extern void *memset(void *, int, unsigned int);
int func_0030D520(Upnp *u)
{
    unsigned char flag = 0;
    int r = 0;
    if (u->started == 0) {
        u->ctx->cb(u, 0, u->ctx->h8);
        u->ctx->cb = 0;
        u->active = 0;
    } else {
        r = func_0030BC98(u, &flag);
        if (r != 0 || flag != 0) {
            if (u->ctx->status != 200 || flag == 0) r = 11;
            func_00310C30(u->ctx->h4);
            u->ctx->h4 = 0;
            func_002F5DB0(u->ctx->h0);
            u->ctx->h0 = 0;
            memset(&u->ctx->status, 0, 0x100C);
            u->ctx->cb(u, r, u->ctx->h8);
            u->ctx->cb = 0;
            u->active = 0;
        }
    }
    return r;
}

