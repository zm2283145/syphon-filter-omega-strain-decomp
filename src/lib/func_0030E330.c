typedef struct {
    int sock;
    int conn;
    int flags;
    char pad0C[4];
    char timer[0x2031 - 0x10];
    unsigned char b2031;
    char pad2032[0x2038 - 0x2032];
    int f2038;
    char pad203C[0x204C - 0x203C];
    int cb;
    char pad2050[0x2070 - 0x2050];
    char req[0x800];
    char path[0x800];
} UpCtxE330;
typedef struct { char pad[0x50]; int state; char pad2[4]; UpCtxE330 *ctx; int f5C; } UpnpE330;
typedef struct { int a; int b; int c; } AddrE330;
extern unsigned char D_0049134E;
extern unsigned char D_0049134F;
extern int D_00529980;
extern int D_0052AC88;
extern int D_0052AC90;
extern char D_004B0158[];
extern int sprintf(char *buf, const char *fmt, ...);
extern unsigned int strlen(const char *s);
extern void *memset(void *p, int c, unsigned int n);
extern int func_0030ECC0(UpnpE330 *u);
extern int func_0030BA90(int *m, int flags, char *buf);
extern int func_0030B5F0(char *a, char *b, char *host, unsigned short *port);
extern int func_00310988(int *p, int kind, int arg);
extern int func_002F5C98(UpCtxE330 *c, char *host, unsigned short port, AddrE330 *a);
extern int func_00310C30(int h);
extern int func_002F5DB0(int s);
extern int Socket_WriteConnected(int s, char *buf, unsigned short len, short *written);
extern int func_003060D8(void *p);
int func_0030E330(UpnpE330 *u, int flags, int cb)
{
    int r;
    int kind;
    AddrE330 addr;
    char host[16];
    unsigned short port;
    short written;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    if (((flags & 0x1000) && D_0049134E == 0) || ((flags & 0x800) && D_0049134F == 0)) {
        r = func_0030BA90(&D_00529980, flags, u->ctx->req);
        if (r != 0) return r;
        r = func_0030B5F0(u->ctx->req, u->ctx->path, host, &port);
        if (r != 0) return r;
        if ((flags & D_00529980) == 0) return 12;
        if (flags == 0x1000) {
            kind = 8;
            D_0052AC88 = 0;
        } else {
            if (flags == 0x800) {
                kind = 7;
                D_0052AC90 = 0;
            } else {
                return 2;
            }
            /* no-op pair (optimised out); changes register choice for the u->ctx reload below (v1, as retail) */
            u->ctx->conn++;
            u->ctx->conn--;
        }
        u->ctx->b2031 = 0;
        u->ctx->f2038 = 0;
        if (func_00310988(&u->ctx->conn, kind, u->f5C) != 0 || u->ctx->conn == 0) return 4;
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
    u->state = 3;
    func_003060D8(u->ctx->timer);
    u->ctx->cb = cb;
    u->ctx->flags = flags;
    return 0;
}

