typedef struct {
    int sock;
    int f4;
    unsigned int type;
    int fC;
    int timer[2];
    char buf[0x100C];
    char pad1024[0x2044 - 0x1024];
    int arg;
    char pad2048[0x2070 - 0x2048];
    char msg[0x100];
} UpnpCtxDF28;
typedef struct {
    char pad[0x50];
    int active;
    int f54;
    UpnpCtxDF28 *ctx;
} UpnpDF28;
typedef struct { int a; int b; int c; } OptsDF28;
extern int func_0030ECC0(UpnpDF28 *u);
extern unsigned char D_0049134C;
extern void *memset(void *p, int c, unsigned int n);
extern int sprintf(char *buf, const char *fmt, ...);
extern unsigned int strlen(const char *s);
extern char D_004B00F8[];
extern char D_004B0148[];
extern char D_004AFAB0[];
extern char D_004AFAE0[];
extern char D_004AFB18[];
extern char D_004AFB48[];
extern int func_002F5C98(int *sock, int a, int port, OptsDF28 *opts);
extern int Socket_WriteAddressed(int sock, char *addr, unsigned short port, char *data, unsigned short len, unsigned short *sent);
extern void func_002F5DB0(int sock);
extern int func_003060D8(int *timer);

int UPnP_SendSsdpSearch(UpnpDF28 *u, unsigned int type, int arg)
{
    OptsDF28 opts;
    unsigned short sent = 0;

    if (u == 0)
        return 2;
    if (u->active)
        return 7;
    if (arg == 0)
        return 2;
    if (func_0030ECC0(u) != 0)
        return 3;
    if (!D_0049134C) {
        memset(u->ctx->buf, 0, 0x100C);
        switch (type) {
        case 0x20:
            sprintf(u->ctx->msg, D_004B00F8, D_004B0148, 0x76C, D_004AFAB0);
            break;
        case 0x40:
            sprintf(u->ctx->msg, D_004B00F8, D_004B0148, 0x76C, D_004AFAE0);
            break;
        case 0x1000:
            sprintf(u->ctx->msg, D_004B00F8, D_004B0148, 0x76C, D_004AFB18);
            break;
        case 0x800:
            sprintf(u->ctx->msg, D_004B00F8, D_004B0148, 0x76C, D_004AFB48);
            break;
        default:
            return 2;
        }
        memset(&opts, 0, sizeof(opts));
        opts.a = 1;
        opts.b = 0x800;
        if (func_002F5C98(&u->ctx->sock, 0, 0x76C, &opts) != 0)
            return 5;
        if (Socket_WriteAddressed(u->ctx->sock, D_004B0148, 0x76C, u->ctx->msg, strlen(u->ctx->msg), &sent) != 0
            || strlen(u->ctx->msg) != sent) {
            func_002F5DB0(u->ctx->sock);
            return 8;
        }
    }
    u->active = 1;
    func_003060D8(u->ctx->timer);
    u->ctx->arg = arg;
    u->ctx->type = type;
    return 0;
}

