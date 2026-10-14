typedef struct UpnpD1E8 UpnpD1E8;
typedef struct {
    int sock;
    int parser;
    int arg;
    char pad[0x1024 - 0xC];
    int status;
    char pad2[0x205C - 0x1028];
    void (*cb)(UpnpD1E8 *u, int r, int arg);
} UpCtxD1E8;
struct UpnpD1E8 { char pad[0x50]; int state; unsigned char busy; char pad2[3]; UpCtxD1E8 *ctx; };
extern int func_0030BC98(UpnpD1E8 *u, unsigned char *done);
extern void func_00310C30(int p);
extern void func_002F5DB0(int s);
extern void *memset(void *d, int c, unsigned int n);
int func_0030D1E8(UpnpD1E8 *u)
{
    unsigned char done = 0;
    int r = func_0030BC98(u, &done);
    UpCtxD1E8 *c;
    if (r == 0 && done == 0) goto out;
    u->busy = 1;
    c = u->ctx;
    if (c->status != 200 || done == 0) {
        u->busy = 0;
        r = 11;
    }
    func_00310C30(c->parser);
    c = u->ctx;
    c->parser = 0;
    func_002F5DB0(c->sock);
    u->ctx->sock = 0;
    memset(&u->ctx->status, 0, 0x100C);
    c = u->ctx;
    c->cb(u, r, c->arg);
    c = u->ctx;
    u->state = 0;
    c->cb = 0;
out:
    return r;
}
