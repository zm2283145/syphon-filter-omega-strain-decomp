typedef struct { char pad[8]; int arg; char pad2[0x2064 - 0xC]; int cb; char pad3[0x2A70 - 0x2068]; char buf[1]; } UpCtxE968;
typedef struct { char pad[0x26]; unsigned short extPort; char pad2[0x50 - 0x28]; int state; unsigned char enabled; char pad3[3]; UpCtxE968 *ctx; } UpnpE968;
extern char D_004B02F0[];
extern int sprintf(char *buf, const char *fmt, ...);
extern int func_0030ECC0(UpnpE968 *u);
extern int func_0030C1B8(UpnpE968 *u, char *a, char *b);
extern int func_003060D8(void *p);
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
