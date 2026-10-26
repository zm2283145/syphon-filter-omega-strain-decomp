/*
 * lib/medius: 12 files, 0030D2B8-0030DD48
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0030D2B8 */
typedef struct UpnpD2B8 UpnpD2B8;
typedef struct {
    int sock;
    int parser;
    int arg;
    char pad[0x1024 - 0xC];
    int status;
    char pad2[0x2060 - 0x1028];
    void (*cb)(UpnpD2B8 *u, int r, int arg);
} UpCtxD2B8;
typedef struct {
    char name[12][0x100];
    char value[12][0x100];
    unsigned int count;
} UpListD2B8;
struct UpnpD2B8 { char pad[4]; char host[0x20]; unsigned short port; char pad26[0x50 - 0x26]; int state; unsigned char busy; char pad2[3]; UpCtxD2B8 *ctx; };
extern int func_0030BC98(UpnpD2B8 *u, unsigned char *done);
extern int func_00310C90(int p, char *s, int a, int b);
extern int func_00310D20(int p, UpListD2B8 **out);
extern int String_CompareN(char *a, char *b, int n);
extern int strtol(char *s, char **end, int base);
extern int func_00310C30(int p);
extern void rt_comm_destroy(int s);
extern void *memset(void *d, int c, unsigned int n);
extern char D_004AFF28[];
extern char D_004B0008[];
extern char D_004B0020[];
extern char D_004B00A8[];
int func_0030D2B8(UpnpD2B8 *u)
{
    unsigned char done = 0;
    int r = func_0030BC98(u, &done);
    UpCtxD2B8 *c;
    if (r == 0 && done == 0) goto out;
    if (u->ctx->status == 200) {
      if (done != 0) {
        if (func_00310C90(u->ctx->parser, D_004AFF28, 0, 1) == 0) {
        UpListD2B8 *list = 0;
        if (func_00310D20(u->ctx->parser, &list) == 0) {
            int a = 0;
            int b = 0;
            unsigned int i = 0;
            unsigned char k = 0;
            for (; i < list->count; i++) {
                    if (String_CompareN(list->name[i], D_004B0008, 0x100) == 0 && String_CompareN(list->value[i], u->host, 0x100) == 0) {
                        a = 1;
                    } else if (String_CompareN(list->name[i], D_004B0020, 0x100) == 0) {
                        if (u->port == (unsigned short)strtol(list->value[i], 0, 10))
                            b = 1;
                    } else if (String_CompareN(list->name[i], D_004B00A8, 0x100) == 0) {
                        k = strtol(list->value[i], 0, 10);
                    }
            }
            if (a && b && k) r = 0; else r = 13;
        }
        }
      } else {
        r = 11;
      }
    } else {
        r = 11;
    }
clean:
    func_00310C30(u->ctx->parser);
    {
        UpCtxD2B8 *c1 = u->ctx;
        c1->parser = 0;
        rt_comm_destroy(c1->sock);
    }
    u->ctx->sock = 0;
    memset(&u->ctx->status, 0, 0x100C);
    {
        UpCtxD2B8 *c2 = u->ctx;
        c2->cb(u, r, c2->arg);
    }
    {
        UpCtxD2B8 *c3 = u->ctx;
        u->state = 0;
        c3->cb = 0;
    }
out:
    return r;
}
/* merge_units: end func_0030D2B8 */

/* merge_units: begin func_0030D520 */
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
#if 0 /* merge_units */
extern int func_0030BC98(Upnp *u, unsigned char *flag);
#endif /* merge_units */
#define func_0030BC98(a0, a1) (func_0030BC98((UpnpD2B8 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_00310C30(int);
#endif /* merge_units */
#define func_00310C30(a0) (func_00310C30((a0))) /* merge_units */

#if 0 /* merge_units */
extern void rt_comm_destroy(int);
#endif /* merge_units */
#define rt_comm_destroy(a0) (rt_comm_destroy((a0))) /* merge_units */

#if 0 /* merge_units */
extern void *memset(void *, int, unsigned int);
#endif /* merge_units */
#define memset(a0, a1, a2) (memset((a0), (a1), (a2))) /* merge_units */

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
            rt_comm_destroy(u->ctx->h0);
            u->ctx->h0 = 0;
            memset(&u->ctx->status, 0, 0x100C);
            u->ctx->cb(u, r, u->ctx->h8);
            u->ctx->cb = 0;
            u->active = 0;
        }
    }
    return r;
}
#undef func_0030BC98 /* merge_units */
#undef func_00310C30 /* merge_units */
#undef rt_comm_destroy /* merge_units */
#undef memset /* merge_units */
/* merge_units: end func_0030D520 */

/* merge_units: begin func_0030D610 */
typedef struct UpnpD610 UpnpD610;
typedef struct {
    char pad[0x2068];
    void (*cb)(UpnpD610 *u, int state, char *name, unsigned short port);
} UpnpCtx_0030D610;
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
    UpnpCtx_0030D610 *ctx;
};
typedef unsigned int IpD610;
typedef struct { IpD610 ip; unsigned short port; } AddrD610;
typedef struct { unsigned short port; unsigned short recvd; unsigned short port2; } InfoD610;
extern int rt_comm_receive_from(int sock, char *buf, unsigned short *port, AddrD610 *data, int len, unsigned short *recvd);
extern int sprintf(char *buf, const char *fmt, ...);
extern char D_004B00B8[];
extern int rt_time_get_time_stamp(int *timer);
extern int rt_time_elapsed(int *timer, unsigned int *elapsed);
extern int Socket_WriteAddressed(int sock, char *addr, unsigned short port, char *data, int len, unsigned short *sent);
extern void func_0030ECF8(UpnpD610 *u);

int process_nat_resolution_timeslice(UpnpD610 *u)
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
    if (rt_comm_receive_from(u->sock, buf, &in.port, &data, 6, &in.recvd) == 0 && in.recvd == 6) {
        if (String_CompareN(buf, u->host, 0x10) == 0 && in.port == u->port2) {
            *(IpD610 *)ip = data.ip;
            in.port2 = data.port;
            sprintf(u->name, D_004B00B8, ip[0], ip[1], ip[2], ip[3]);
            u->started = 1;
            u->state = 0;
            u->port = (in.port2 >> 8) | (in.port2 << 8);
            rt_time_get_time_stamp(u->timer);
            u->active = 0;
            u->ctx->cb(u, u->state, u->name, u->port);
            func_0030ECF8(u);
        } else {
            ret = 9;
        }
    }
    if (u->active) {
        rt_time_elapsed(u->timer, &elapsed);
        if (elapsed > 800) {
            if (u->retries < 5) {
                pkt[2] = -0x1C;
                sent = 0;
                if (Socket_WriteAddressed(u->sock, u->host, u->port2, pkt, 4, &sent) == 0 && sent == 4) {
                    rt_time_get_time_stamp(u->timer);
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
/* merge_units: end func_0030D610 */

/* merge_units: begin func_0030D830 */
typedef struct {
    int sock;
    char pad[0x24];
    char host[0x10];
    unsigned short port;
    char pad2[6];
    int timer[3];
    unsigned char active;
} UpnpD830;
#if 0 /* merge_units */
extern int Socket_WriteAddressed(int sock, void *addr, unsigned short port, void *data, int len, unsigned short *sent);
#endif /* merge_units */
#define Socket_WriteAddressed(a0, a1, a2, a3, a4, a5) (Socket_WriteAddressed((a0), (char *)(a1), (a2), (char *)(a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void rt_time_get_time_stamp(int *timer);
#endif /* merge_units */
#define rt_time_get_time_stamp(a0) ((void)rt_time_get_time_stamp((a0))) /* merge_units */

int process_heartbeat_timeslice(UpnpD830 *u)
{
    char pkt[4];
    unsigned short sent = 0;
    unsigned int elapsed;
    if (u->active) {
        rt_time_elapsed(u->timer, &elapsed);
        if (elapsed > 5000) {
            pkt[3] = 0xD4;
            Socket_WriteAddressed(u->sock, u->host, u->port, pkt, 4, &sent);
            rt_time_get_time_stamp(u->timer);
        }
    }
    return 0;
}
#undef Socket_WriteAddressed /* merge_units */
#undef rt_time_get_time_stamp /* merge_units */
/* merge_units: end func_0030D830 */

/* merge_units: begin func_0030D8B0 */
typedef struct { int f0; int f4; int f8; int state; char pad[0x2023]; unsigned char wide; unsigned char retried; } UpCtxD8B0;
typedef struct {
    char pad[0x26];
    unsigned short port26;
    char host[0x10];
    unsigned short port38;
    char pad2[0x1E];
    UpCtxD8B0 *ctx;
} UpnpD8B0;

extern char *strncpy(char *, const char *, unsigned int);
extern int func_0030E148(UpnpD8B0 *u, void *cb);
extern int func_0030E330(UpnpD8B0 *u, int arg, void *cb);
extern int UPnP_GetStatusInfo(UpnpD8B0 *u, int arg, void *cb);
extern int UPnP_GetExternalIPAddress(UpnpD8B0 *u, int arg, void *cb);
extern int UPnP_GetPortMappingNumberOfEntries(UpnpD8B0 *u, int arg, void *cb);
extern int UPnP_AddPortMapping(UpnpD8B0 *u, int arg, unsigned short port, void *cb);
extern int func_0030EA40(UpnpD8B0 *u, char *host, unsigned short port, void *cb);
extern void func_0030DB68();
extern void func_0030DBD8();
extern void func_0030DC30();
extern void func_0030DC98();
extern void func_0030DCF0();
extern void func_0030DD48();
extern void func_0030DDA0();

int func_0030D8B0(UpnpD8B0 *u)
{
    int r = 0;
    char host[16];
    unsigned short port;

    switch (u->ctx->state) {
    case 0: case 1: break;
    case 2:
        r = func_0030E148(u, func_0030DB68);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 3:
        if (!u->ctx->wide) r = func_0030E330(u, 0x1000, func_0030DBD8); else r = func_0030E330(u, 0x800, func_0030DBD8);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 4:
        if (!u->ctx->wide) r = UPnP_GetStatusInfo(u, 0x1000, func_0030DC30); else r = UPnP_GetStatusInfo(u, 0x800, func_0030DC30);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 5:
        if (!u->ctx->wide) r = UPnP_GetExternalIPAddress(u, 0x1000, func_0030DC98); else r = UPnP_GetExternalIPAddress(u, 0x800, func_0030DC98);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 6:
        if (!u->ctx->wide) r = UPnP_GetPortMappingNumberOfEntries(u, 0x1000, func_0030DCF0); else r = UPnP_GetPortMappingNumberOfEntries(u, 0x800, func_0030DCF0);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 7:
        if (!u->ctx->wide) r = UPnP_AddPortMapping(u, 0x1000, u->port26, func_0030DD48); else r = UPnP_AddPortMapping(u, 0x800, u->port26, func_0030DD48);
        if (r == 0) u->ctx->state = 1;
        else {
            UpCtxD8B0 *c = u->ctx;
            if (c->retried == 0) {
                c->state = 6; c->retried = 1;
            } else {
                c->state = 8;
            }
        }
        break;
    case 8:
        port = u->port38;
        strncpy(host, u->host, 16);
        r = func_0030EA40(u, host, port, func_0030DDA0);
        if (r == 0) u->ctx->state = 1;
        else if (u->ctx != 0) u->ctx->state = 0;
        break;
    }
    return r;
}
/* merge_units: end func_0030D8B0 */

/* merge_units: begin func_0030DB38 */
typedef struct { int f0; int f4; int f8; int state; char pad[0x2023]; unsigned char retried; } ScfConnCtx;
typedef struct { char pad[0x58]; ScfConnCtx *ctx; } ScfConn;
void func_0030DB38(ScfConn *o, int err)
{
    if (o == 0) return;
    if (err == 0) o->ctx->state = 2;
    else o->ctx->state = 8;
}
/* merge_units: end func_0030DB38 */

/* merge_units: begin func_0030DB68 */
void func_0030DB68(ScfConn *o, int err, int flags)
{
    if (o == 0) return;
    if (err == 0) {
        if (flags & 0x1000) { o->ctx->state = 3; return; }
        if (flags & 0x800) { o->ctx->retried = 1; o->ctx->state = 3; return; }
    }
    o->ctx->state = 8;
}
/* merge_units: end func_0030DB68 */

/* merge_units: begin func_0030DBD8 */
#define SCF_CONN_RESULT(name, okstate) void name(ScfConn *o, int err) { ScfConnCtx *c; if (o == 0) return; c = o->ctx; if (err == 0) { c->state = okstate; return; } if (c->retried == 0) { c->retried = 1; o->ctx->state = 3; return; } c->state = 8; }
SCF_CONN_RESULT(func_0030DBD8, 5)
/* merge_units: end func_0030DBD8 */

/* merge_units: begin func_0030DC30 */
typedef struct {
    char pad0[0xC];
    int state;
    char pad10[0x2033 - 0x10];
    unsigned char started;
} St;
typedef struct {
    char pad0[0x58];
    St *st;
} Obj;
void func_0030DC30(Obj *o, int a1, int a2, int a3)
{
    if (o == 0) return;
    if (a1 == 0 && a3 == 2) {
        o->st->state = 5;
        return;
    }
    if (o->st->started == 0) {
        o->st->started = 1;
        o->st->state = 3;
        return;
    }
    o->st->state = 8;
}
/* merge_units: end func_0030DC30 */

/* merge_units: begin func_0030DC98 */
SCF_CONN_RESULT(func_0030DC98, 6)
/* merge_units: end func_0030DC98 */

/* merge_units: begin func_0030DCF0 */
SCF_CONN_RESULT(func_0030DCF0, 7)
/* merge_units: end func_0030DCF0 */

/* merge_units: begin func_0030DD48 */
typedef struct {
    char pad[0xC];
    int xC;
    char pad2[0x2023];
    unsigned char b2033;
} TDD48;

typedef struct {
    char pad[0x58];
    TDD48 *x58;
} SDD48;

void func_0030DD48(SDD48 *s, int x)
{
    if (s == 0) {
        return;
    }
    if (x == 0) {
        s->x58->xC = 8;
        return;
    }
    if (s->x58->b2033 == 0) {
        s->x58->b2033 = 1;
        s->x58->xC = 3;
        return;
    }
    s->x58->xC = 8;
}
/* merge_units: end func_0030DD48 */
