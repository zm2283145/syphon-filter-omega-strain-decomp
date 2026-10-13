typedef struct UpnpD610 UpnpD610;
typedef struct {
    char pad[0x2068];
    void (*cb)(UpnpD610 *u, int state, char *name, unsigned short port);
} UpnpCtx;
struct UpnpD610 {
    int sock;
    char pad4[0x10];
    char name[0x12];
    unsigned short port;
    char host[0x10];
    unsigned short port2;
    char pad3a[2];
    int state;
    int timer[2];
    unsigned int retries;
    unsigned char started;
    char pad4d[3];
    int active;
    char pad54[4];
    UpnpCtx *ctx;
};
typedef unsigned int IpD610;
typedef struct { IpD610 ip; unsigned short port; } AddrD610;
typedef struct { unsigned short port; unsigned short recvd; unsigned short port2; } InfoD610;
extern int func_002F61A0(int sock, char *buf, unsigned short *port, AddrD610 *data, int len, unsigned short *recvd);
extern int String_CompareN(char *a, char *b, int n);
extern int sprintf(char *buf, const char *fmt, ...);
extern char D_004B00B8[];
extern int func_003060D8(int *timer);
extern int func_003060F0(int *timer, unsigned int *elapsed);
extern int Socket_WriteAddressed(int sock, char *addr, unsigned short port, char *data, int len, unsigned short *sent);
extern void func_0030ECF8(UpnpD610 *u);

int func_0030D610(UpnpD610 *u)
{
    AddrD610 data;
    unsigned char ip[4];
    char buf[0x10];
    InfoD610 in;
    char pkt[4];
    unsigned short sent;
    unsigned int elapsed;
    int ret = 0;

    in.recvd = 0;
    in.port2 = 0;
    if (func_002F61A0(u->sock, buf, &in.port, &data, 6, &in.recvd) == 0 && in.recvd == 6) {
        if (String_CompareN(buf, u->host, 0x10) == 0 && in.port == u->port2) {
            *(IpD610 *)ip = data.ip;
            in.port2 = data.port;
            sprintf(u->name, D_004B00B8, ip[0], ip[1], ip[2], ip[3]);
            u->started = 1;
            u->state = 0;
            u->port = (in.port2 >> 8) | (in.port2 << 8);
            func_003060D8(u->timer);
            u->active = 0;
            u->ctx->cb(u, u->state, u->name, u->port);
            func_0030ECF8(u);
        } else {
            ret = 9;
        }
    }
    if (u->active) {
        func_003060F0(u->timer, &elapsed);
        if (elapsed > 800) {
            if (u->retries < 5) {
                pkt[2] = -0x1C;
                sent = 0;
                if (Socket_WriteAddressed(u->sock, u->host, u->port2, pkt, 4, &sent) == 0 && sent == 4) {
                    func_003060D8(u->timer);
                    u->retries++;
                } else {
                    u->state = 8;
                    u->active = 0;
                    u->ctx->cb(u, 8, u->name, u->port);
                    func_0030ECF8(u);
                }
            } else {
                u->state = 6;
                u->active = 0;
                u->ctx->cb(u, 6, u->name, u->port);
                func_0030ECF8(u);
            }
        }
    }
    return ret;
}




