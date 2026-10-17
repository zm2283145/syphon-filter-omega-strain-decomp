typedef struct {
    int sock;
    int conn;
    int flags;
    char pad0C[4];
    char timer[0x624 - 0x10];
    char url[0x2031 - 0x624];
    unsigned char b2031;
    char pad2032[0x2038 - 0x2032];
    int f2038;
    char pad203C[0x2048 - 0x203C];
    int cb;
    char pad204C[0x2070 - 0x204C];
    char req[0x800];
    char path[0x800];
} UpCtxE148;
typedef struct { char pad[0x50]; int state; char pad2[4]; UpCtxE148 *ctx; int f5C; } UpnpE148;
typedef struct { int a; int b; int c; } AddrE148;
extern unsigned char D_0049134D;
extern int D_00529980;
extern char D_004B0158[];
extern int sprintf(char *buf, const char *fmt, ...);
extern unsigned int strlen(const char *s);
extern void *memset(void *p, int c, unsigned int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int func_0030ECC0(UpnpE148 *u);
extern int func_0030B5F0(char *a, char *b, char *host, unsigned short *port);
extern int func_00310988(int *p, int kind, int arg);
extern int func_002F5C98(UpCtxE148 *c, char *host, unsigned short port, AddrE148 *a);
extern int func_00310C30(int h);
extern int func_002F5DB0(int s);
extern int Socket_WriteConnected(int s, char *buf, unsigned short len, unsigned short *written);
extern int func_003060D8(void *p);
int func_0030E148(UpnpE148 *u, int cb)
{
    int r;
    AddrE148 addr;
    char host[16];
    unsigned short port;
    unsigned short written;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    if (D_0049134D == 0) {
        memset(&D_00529980, 0, 0x1304);
        u->ctx->b2031 = 0;
        u->ctx->f2038 = 0;
        strncpy(u->ctx->req, u->ctx->url, 0x200);
        r = func_0030B5F0(u->ctx->req, u->ctx->path, host, &port);
        if (r != 0) return r;
        if (func_00310988(&u->ctx->conn, 0, u->f5C) != 0 || u->ctx->conn == 0) return 4;
        memset(&addr, 0, sizeof(addr));
        addr.b = 0x800;
        addr.a = 0;
        if (func_002F5C98(u->ctx, host, port, &addr) != 0) {
            func_00310C30(u->ctx->conn);
            return 5;
        }
        sprintf(u->ctx->req, D_004B0158, u->ctx->path, host, port);
        if (Socket_WriteConnected(u->ctx->sock, u->ctx->req, strlen(u->ctx->req), &written) != 0
            || strlen(u->ctx->req) != written) {
            func_002F5DB0(u->ctx->sock);
            func_00310C30(u->ctx->conn);
            return 8;
        }
    }
    u->state = 2;
    func_003060D8(u->ctx->timer);
    u->ctx->cb = cb;
    return 0;
}

