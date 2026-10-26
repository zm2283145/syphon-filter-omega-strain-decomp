/*
 * lib/medius: 10 files, 002DDAC8-002DDF58
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DDAC8 */
extern void rt_time_get_local(int *);
int NetIGetLocalTime(int *p)
{
    int t[4];
    if (p == 0) return 0x17;
    rt_time_get_local(t);
    *p = t[0];
    return 0;
}
/* merge_units: end func_002DDAC8 */

/* merge_units: begin func_002DDB08 */
extern int D_0058806C;
int NetIGetTime(int* out)
{
    if (out == 0)
        return 0x17;
    *out = D_0058806C;
    return 0;
}
/* merge_units: end func_002DDB08 */

/* merge_units: begin func_002DDB30 */
extern int NetGetConnInfo(unsigned int, int *);
int NetIGetSessionMasterClientIndex(int *out, unsigned int i)
{
    int p = 0;
    int r;
    if (i >= 4) return 0x17;
    if (out == 0) return 0x17;
    *out = 0x100;
    r = NetGetConnInfo(i, &p);
    if (r) return r;
    if (p) *out = *(int *)(p + 0x404);
    return 0;
}
/* merge_units: end func_002DDB30 */

/* merge_units: begin func_002DDB98 */
int NetIGetConnectStatus(int *out, unsigned int i)
{
    int p = 0;
    int r;
    if (i >= 4) return 0x17;
    if (out == 0) return 0x17;
    *out = 0xFFFFFF;
    r = NetGetConnInfo(i, &p);
    if (r) return r;
    if (p) *out = *(int *)(p + 0x438);
    return 0;
}
/* merge_units: end func_002DDB98 */

/* merge_units: begin func_002DDC00 */
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, unsigned char ***);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (int *)(a1))) /* merge_units */

int NetIGetValidClientCount(int *out, unsigned int idx)
{
    unsigned char **p = 0;
    unsigned int i = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (idx >= 4) return 0x17;
    r = NetGetConnInfo(idx, &p);
    if (r) return r;
    if (p == 0) return r;
    for (; i < 0x100; i++) {
        if (p[i] && p[i][0x28] == 1) (*out)++;
    }
    return 0;
}
#undef NetGetConnInfo /* merge_units */
/* merge_units: end func_002DDC00 */

/* merge_units: begin func_002DDCA0 */
extern void *memset(void *, int, unsigned int);
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, char **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (int *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int NetIGetConnectStatus(int *, unsigned int);
#endif /* merge_units */
#define NetIGetConnectStatus(a0, a1) (NetIGetConnectStatus((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int NetIGetValidClientCount(int *, unsigned int);
#endif /* merge_units */
#define NetIGetValidClientCount(a0, a1) (NetIGetValidClientCount((a0), (a1))) /* merge_units */

int NetIGetConnectionStatus(int *out, unsigned int idx)
{
    char *p = 0;
    int r;
    if (out == 0) return 0x17;
    memset(out, 0, 0xC);
    if (idx >= 4) return 0x17;
    r = NetGetConnInfo(idx, &p);
    if (r) return r;
    if (p == 0) return 0xF;
    r = NetIGetConnectStatus(out, idx);
    if (r) return r;
    r = NetIGetValidClientCount(out + 1, idx);
    if (r) return r;
    out[2] = out[1] + *(int *)(p + 0x440);
    return r;
}
#undef NetGetConnInfo /* merge_units */
#undef NetIGetConnectStatus /* merge_units */
#undef NetIGetValidClientCount /* merge_units */
/* merge_units: end func_002DDCA0 */

/* merge_units: begin func_002DDD50 */
extern char *strncpy(char *, const char *, unsigned int);
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, char **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (int *)(a1))) /* merge_units */

int NetIGetServerVersion(char *dst, unsigned int idx)
{
    char *p = 0;
    int r;
    if (idx >= 4) return 0x17;
    if (dst == 0) return 0x17;
    memset(dst, 0, 0x10);
    r = NetGetConnInfo(idx, &p);
    if (r) return r;
    if (p) {
        strncpy(dst, p + 0x418, 0x10);
        return 0;
    }
    return r;
}
#undef NetGetConnInfo /* merge_units */
/* merge_units: end func_002DDD50 */

/* merge_units: begin func_002DDDD0 */
void NetSetClientTargetActive(unsigned char *o, int bit)
{
    if (o == 0 || (unsigned int)bit >= 0x100) return;
    if (bit < *(int *)(o + 0x24)) *(int *)(o + 0x24) = bit;
    if (*(int *)(o + 0x28) < bit) *(int *)(o + 0x28) = bit;
    o[bit >> 3] |= 1 << (bit & 7);
}
/* merge_units: end func_002DDDD0 */

/* merge_units: begin func_002DDE30 */
typedef struct { unsigned char bits[0x24]; int f24; int f28; } Set;
typedef struct { char p[0x400]; int f400; char p2[0x40]; int f444; } Ctx;
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, Ctx **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (int *)(a1))) /* merge_units */

extern int NetIGetClient(int *, unsigned int, int);
#if 0 /* merge_units */
extern void NetSetClientTargetActive(Set *, int);
#endif /* merge_units */
#define NetSetClientTargetActive(a0, a1) (NetSetClientTargetActive((unsigned char *)(a0), (a1))) /* merge_units */

void FilterTargetClientBitmask(Set *s, unsigned int a, int (*cb)(int, int))
{
    Ctx *ctx[1];
    int x[1];
    int i;
    ctx[0] = 0;
    if (a >= 4) return;
    if (cb == 0) return;
    if (s == 0) return;
    s->f24 = 0x100;
    s->f28 = -1;
    if (NetGetConnInfo(a, ctx)) return;
    if (ctx[0] == 0) return;
    s->f24 = ctx[0]->f444;
    {
        unsigned char *p = &s->bits[0x20];
        int n = 0x20;
        do { n--; *p-- = 0; } while (n >= 0);
    }
    for (i = 0; i < ctx[0]->f444; i++) {
        x[0] = 0;
        NetIGetClient(x, a, i);
        if (x[0] && i != ctx[0]->f400 && cb(i, ctx[0]->f400)) NetSetClientTargetActive(s, i);
    }
}
#undef NetGetConnInfo /* merge_units */
#undef NetSetClientTargetActive /* merge_units */
/* merge_units: end func_002DDE30 */

/* merge_units: begin func_002DDF58 */
extern unsigned short DmeToRtMsgConnectionIndex(unsigned int);
extern int rt_msg_client_send_target(unsigned short, unsigned short, void *, void *, unsigned short);
extern int printf(const char *, ...);
int Net_SendConvertRecipient(signed char a, unsigned int idx, int to, unsigned int len, void *data)
{
    int r; unsigned short recip;
    recip = to;
    if (to == -1) recip = 0xFFFE;
    else if (to == 0xFFFF) recip = 0xFFFF;
    r = rt_msg_client_send_target(DmeToRtMsgConnectionIndex(idx), recip, (void *)(int)a, data, len);
    if (r) {
        printf("SendPacket error sending message, msg error code = %d\n", r);
        return 0xD;
    }
    return r;
}
/* merge_units: end func_002DDF58 */
