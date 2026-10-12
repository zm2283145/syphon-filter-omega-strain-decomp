typedef struct { char pad[0x2068]; void *cb; } UpCtxEA40;
typedef struct {
    int sock;
    char pad[0x24];
    char host[0x10];
    unsigned short port;
    char pad2[2];
    int flag;
    int timer[2];
    int tries;
    char pad3[4];
    int state;
    char pad4[4];
    UpCtxEA40 *ctx;
} UpnpEA40;
extern void *memset(void *d, int c, unsigned int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int func_0030ECC0(UpnpEA40 *u);
extern int Socket_WriteAddressed(int sock, void *addr, unsigned short port, void *data, int len, unsigned short *sent);
extern void func_0030ECF8(UpnpEA40 *u);
extern int func_003060D8(void *p);
int func_0030EA40(UpnpEA40 *u, const char *host, unsigned short port, void *cb)
{
    char pkt[4];
    unsigned short sent = 0;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (host == 0) return 2;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    memset(u->host, 0, 0x28);
    strncpy(u->host, host, 0x10);
    u->port = port;
    u->flag = 0;
    u->ctx->cb = cb;
    pkt[2] = 0xE4;
    if (Socket_WriteAddressed(u->sock, u->host, u->port, pkt, 4, &sent) != 0 || sent != 4) {
        func_0030ECF8(u);
        return 8;
    }
    func_003060D8(u->timer);
    u->tries++;
    u->state = 10;
    return 0;
}
