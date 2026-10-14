/*
 * lib/medius: 4 files, 0030E8A0-0030EB60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0030E8A0 */
typedef struct { char pad[8]; int arg; char pad2[0x2060 - 0xC]; int cb; char pad3[0x2A70 - 0x2064]; char buf[1]; } UpCtxE8A0;
typedef struct { char pad[0x24]; unsigned short port; unsigned short extPort; char pad2[0x50 - 0x28]; int state; char pad3[4]; UpCtxE8A0 *ctx; } UpnpE8A0;
extern char D_004B02F0[];
extern int sprintf(char *buf, const char *fmt, ...);
extern int func_0030ECC0(UpnpE8A0 *u);
extern int func_0030C1B8(UpnpE8A0 *u, char *a, char *b);
extern int func_003060D8(void *p);
int UPnP_GetSpecificPortMappingEntry(UpnpE8A0 *u, int arg, int cb)
{
    int r;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    u->ctx->arg = arg;
    sprintf(u->ctx->buf, D_004B02F0, u->extPort);
    r = func_0030C1B8(u, "GetSpecificPortMappingEntry", u->ctx->buf);
    if (r == 0) {
        u->state = 8;
        func_003060D8((char *)u->ctx + 0x10);
        u->ctx->cb = cb;
    }
    return r;
}
/* merge_units: end func_0030E8A0 */

/* merge_units: begin func_0030E968 */
typedef struct { char pad[8]; int arg; char pad2[0x2064 - 0xC]; int cb; char pad3[0x2A70 - 0x2068]; char buf[1]; } UpCtxE968;
typedef struct { char pad[0x26]; unsigned short extPort; char pad2[0x50 - 0x28]; int state; unsigned char enabled; char pad3[3]; UpCtxE968 *ctx; } UpnpE968;
#if 0 /* merge_units */
extern int func_0030ECC0(UpnpE968 *u);
#endif /* merge_units */
#define func_0030ECC0(a0) (func_0030ECC0((UpnpE8A0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_0030C1B8(UpnpE968 *u, char *a, char *b);
#endif /* merge_units */
#define func_0030C1B8(a0, a1, a2) (func_0030C1B8((UpnpE8A0 *)(a0), (a1), (a2))) /* merge_units */

int UPnP_DeletePortMapping(UpnpE968 *u, int arg, int cb)
{
    int r = 0;
    if (u == 0) return 2;
    if (u->state != 0) return 7;
    if (cb == 0) return 2;
    if (func_0030ECC0(u) != 0) return 3;
    if (u->enabled == 0) goto ok;
    u->ctx->arg = arg;
    sprintf(u->ctx->buf, D_004B02F0, u->extPort);
    r = func_0030C1B8(u, "DeletePortMapping", u->ctx->buf);
    /* no-op: extra references raise cb's register-allocation priority (retail: cb=s1, r=s2, arg=s3) */
    cb++;
    cb--;
    if (r == 0) {
ok:
        u->state = 9;
        func_003060D8((char *)u->ctx + 0x10);
        u->ctx->cb = cb;
    }
    return r;
}
#undef func_0030ECC0 /* merge_units */
#undef func_0030C1B8 /* merge_units */
/* merge_units: end func_0030E968 */

/* merge_units: begin func_0030EA40 */
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
#if 0 /* merge_units */
extern int func_0030ECC0(UpnpEA40 *u);
#endif /* merge_units */
#define func_0030ECC0(a0) (func_0030ECC0((UpnpE8A0 *)(a0))) /* merge_units */

extern int Socket_WriteAddressed(int sock, void *addr, unsigned short port, void *data, int len, unsigned short *sent);
extern void func_0030ECF8(UpnpEA40 *u);
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
#undef func_0030ECC0 /* merge_units */
/* merge_units: end func_0030EA40 */

/* merge_units: begin func_0030EB60 */
typedef struct { char pad[0x14]; char name[0x12]; unsigned short port; char pad2[0x28]; int busy; } ScfSvc_B60;
int func_0030EB60(ScfSvc_B60 *o, char *dst, unsigned short *port)
{
    int ret = 2;
    if (o == 0) return ret;
    if (o->busy != 0) return 7;
    if (dst == 0) return ret;
    if (port == 0) return ret;
    strncpy(dst, o->name, 16);
    *port = o->port;
    return 0;
}
/* merge_units: end func_0030EB60 */
