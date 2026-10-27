/*
 * lib/libnet: 30 files, 0034A6E8-0034B698
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034A6E8 */
typedef struct Blk {
    int used;
    int f4;
    int size;
    int fC;
    char pad10[0x2C - 0x10];
    struct Blk *self;
    char pad30[0x3C - 0x30];
    int f3C;
} Blk;
typedef struct Ctx {
    char pad0[0x18];
    unsigned int total;
    char *base;
    char pad20[0x2C - 0x20];
    char *remote;
    char pad30[0x3C - 0x30];
    unsigned int cur;
} Ctx;


int libnetb_get_valid_data_header_ptr(Ctx *c, Blk **out, unsigned char *flag)
{
    unsigned int off;
    Blk *b;
    int ret = 2;

    if (c != 0 && out != 0) {
        *out = 0;
        if (flag != 0) {
            *flag = 0;
            off = c->cur;
            b = (Blk *)(c->base + off);
            while (b->f4 == 1) {
                off = off + b->size + 0x40;
                if (off >= c->total)
                    off = 0;
                b = (Blk *)(c->base + off);
                if (off == c->cur) {
                    *out = 0;
                    *flag = 0;
                    return 0;
                }
            }
            if (b->used == 1 && b->f3C == 1) {
                *out = b;
                *flag = 1;
            } else {
                *out = 0;
                *flag = 0;
            }
            ret = 0;
        }
    }
    return ret;
}
/* merge_units: end func_0034A6E8 */

/* merge_units: begin func_0034A7A8 */
typedef struct { char pad[0x30]; int bufsize; } NetCd_7A8;
extern int scePrintf(const char *fmt, ...);
extern int sceSifMCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *edata);
int Libnet_CallRpc(NetCd_7A8 *cd, int fno, void *buf, int ssize, int rsize)
{
    int bsize;
    ssize = (ssize + 63) & ~63;
    rsize = (rsize + 63) & ~63;
    bsize = cd->bufsize;
    if (bsize < ssize || bsize < rsize) {
        scePrintf("CallRpc() in Libnet send:%d, recv:%d, max:%d
", ssize, rsize, bsize);
        return -0x21F;
    }
    return sceSifMCallRpc(cd, fno, 0, buf, ssize, buf, rsize, 0, 0);
}
/* merge_units: end func_0034A7A8 */

/* merge_units: begin func_0034A828 */
typedef struct { char pad[0x30]; int bufsize; } NetCd_828;
extern void *memcpy(void *d, const void *s, unsigned int n);
int MemcpyD(NetCd_828 *cd, char *buf, int idx, void *src, int len)
{
    int room = cd->bufsize - idx * 4;
    if (src == 0) return 0;
    if (len < 0 || room < len) return -0x21F;
    memcpy(buf + idx * 4, src, len);
    return 0;
}
/* merge_units: end func_0034A828 */

/* merge_units: begin func_0034A880 */
typedef struct { char pad[0x30]; int bufsize; } NetCd_880;
int MemcpyS(NetCd_880 *cd, void *dst, char *buf, int idx, int len)
{
    int room = cd->bufsize - idx * 4;
    if (dst == 0) return 0;
    if (len < 0 || room < len) return -0x21F;
    memcpy(dst, buf + idx * 4, len);
    return 0;
}
/* merge_units: end func_0034A880 */

/* merge_units: begin func_0034A8D8 */
typedef struct { char pad[0x30]; int bufsize; } NetCd_8D8;
extern unsigned int strlen(const char *s);
extern char *Libc_Strcpy(char *d, const char *s);
int StrcpyD(NetCd_8D8 *cd, char *buf, int idx, char *s)
{
    int room = cd->bufsize - idx * 4;
    int n;
    if (s == 0) return 0;
    n = strlen(s) + 1;
    if (n < 0 || room < n) return -0x21F;
    Libc_Strcpy(buf + idx * 4, s);
    return n;
}
/* merge_units: end func_0034A8D8 */

/* merge_units: begin func_0034A968 */
int StrcpyS(void *cd, char *dst, char *buf, int idx)
{
    if (dst == 0) return 0;
    Libc_Strcpy(dst, buf + idx * 4);
    return 0;
}
/* merge_units: end func_0034A968 */

/* merge_units: begin func_0034A9A8 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


int sceInetPoll(void *cd, unsigned int *buf, void *dst, int n, int x)
{
    int r;
    buf[0] = n; buf[1] = x;
    r = MemcpyD(cd, buf, 2, dst, n * 8);
    if (r < 0) return r;
    if (Libnet_CallRpc(cd, 0x14, buf, n * 8 + 8, n * 8 + 4) < 0) return -0x21E;
    r = MemcpyS(cd, dst, buf, 2, n * 8);
    if (r < 0) return r;
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034A9A8 */

/* merge_units: begin func_0034AA50 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


int sceInetName2Address(void *cd, unsigned int *buf, unsigned int flags, void *dst, char *str, unsigned int b, unsigned int c, ...)
{
    int n;
    buf[0] = flags; buf[1] = b; buf[2] = c; buf[3] = 0;
    if (flags & 0x80) {
        __builtin_va_list ap;
        __builtin_stdarg_start(ap, c);
        buf[3] = __builtin_va_arg(ap, unsigned int);
        __builtin_va_end(ap);
    }
    n = StrcpyD(cd, buf, 5, str);
    if (n < 0) return n;
    buf[4] = n;
    if (Libnet_CallRpc(cd, 6, buf, n + 0x14, 0x14) < 0) return -0x21E;
    n = MemcpyS(cd, dst, buf, 1, 16);
    if (n < 0) return n;
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034AA50 */

/* merge_units: begin func_0034AB38 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */

int sceInetAddress2String(void *cd, unsigned int *buf, char *dst, int n, void *src)
{
    int r;
    buf[0] = n;
    r = MemcpyD(cd, buf, 1, src, 16);
    if (r < 0) return r;
    if (Libnet_CallRpc(cd, 7, buf, 0x14, n + 0x14) < 0) return -0x21E;
    r = StrcpyS(cd, dst, buf, 5);
    if (r < 0) return r;
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034AB38 */

/* merge_units: begin func_0034ABE0 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


int sceInetAddress2Name(void *cd, unsigned int *buf, unsigned int flags, char *dst, int len, void *addr, unsigned int c, unsigned int d, ...)
{
    int r;
    buf[2] = c; buf[3] = d; buf[8] = 0; buf[0] = flags; buf[1] = len;
    if (flags & 0x80) {
        __builtin_va_list ap;
        __builtin_stdarg_start(ap, d);
        buf[8] = __builtin_va_arg(ap, unsigned int);
        __builtin_va_end(ap);
    }
    r = MemcpyD(cd, buf, 4, addr, 16);
    if (r < 0) return r;
    if (Libnet_CallRpc(cd, 0x12, buf, 0x24, len + 0x20) < 0) return -0x21E;
    r = StrcpyS(cd, dst, buf, 8);
    if (r < 0) return r;
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034ABE0 */

/* merge_units: begin func_0034ACC8 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


int sceInetCreate(void *cd, unsigned int *buf, void *src)
{
    int r;
    r = MemcpyD(cd, buf, 1, src, 0x40);
    if (r < 0) return r;
    if (Libnet_CallRpc(cd, 1, buf, 0x44, 4) < 0) return -0x21E;
    return buf[0] ? buf[0] : -0x21C;
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034ACC8 */

/* merge_units: begin func_0034AD40 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#define NET_RPC0(name, fno) int name(void *cd, unsigned int *buf) { if (Libnet_CallRpc(cd, fno, buf, 0, 4) < 0) return -0x21E; return buf[0]; }
#define NET_RPC1(name, fno) int name(void *cd, unsigned int *buf, unsigned int a) { buf[0] = a; if (Libnet_CallRpc(cd, fno, buf, 4, 4) < 0) return -0x21E; return buf[0]; }
#define NET_RPC2(name, fno) int name(void *cd, unsigned int *buf, unsigned int a, unsigned int b) { buf[0] = a; buf[1] = b; if (Libnet_CallRpc(cd, fno, buf, 8, 4) < 0) return -0x21E; return buf[0]; }

NET_RPC2(sceInetOpen, 0x2)
#undef Libnet_CallRpc /* merge_units */
/* merge_units: end func_0034AD40 */

/* merge_units: begin func_0034AD88 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

NET_RPC2(sceInetClose, 0x3)
#undef Libnet_CallRpc /* merge_units */
/* merge_units: end func_0034AD88 */

/* merge_units: begin func_0034ADD0 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


int sceInetRecv(void *cd, int *buf, int a, void *dst, int len, int *p, int x)
{
    int r;
    buf[0] = a;
    if (p) buf[1] = *p; else buf[1] = 0;
    buf[2] = len; buf[3] = x;
    if (Libnet_CallRpc(cd, 4, buf, 16, len + 8) < 0) return -0x21E;
    if (buf[0] < 0) return buf[0];
    if (p) *p = buf[1];
    r = MemcpyS(cd, dst, buf, 2, buf[0]);
    if (r < 0) return r;
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034ADD0 */

/* merge_units: begin func_0034AE98 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


int sceInetRecvFrom(void *cd, int *buf, int a, void *dst, int len, int *p, void *addr, int *alen, int x)
{
    int r;
    buf[0] = a;
    if (p) buf[1] = *p; else buf[1] = 0;
    buf[2] = len; buf[3] = x;
    if (Libnet_CallRpc(cd, 0xD, buf, 16, len + 0x1C) < 0) return -0x21E;
    if (buf[0] < 0) return buf[0];
    if (p) *p = buf[1];
    r = MemcpyS(cd, addr, buf, 2, 16);
    if (r < 0) return r;
    if (alen) *alen = buf[6];
    r = MemcpyS(cd, dst, buf, 7, buf[0]);
    if (r < 0) return r;
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034AE98 */

/* merge_units: begin func_0034AFA8 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


int sceInetSend(void *cd, int *buf, int a, void *src, int len, int *p, int x)
{
    int r;
    buf[0] = a;
    if (p) buf[1] = *p; else buf[1] = 0;
    buf[2] = len; buf[3] = x;
    r = MemcpyD(cd, buf, 4, src, len);
    if (r < 0) return r;
    if (Libnet_CallRpc(cd, 5, buf, len + 16, 8) < 0) return -0x21E;
    if (p) *p = buf[1];
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034AFA8 */

/* merge_units: begin func_0034B050 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


int sceInetSendTo(void *cd, int *buf, int a, void *src, int len, int *p, void *addr, int x, int y)
{
    int r;
    buf[0] = a;
    if (p) buf[1] = *p; else buf[1] = 0;
    buf[2] = len; buf[3] = y; buf[4] = x;
    r = MemcpyD(cd, buf, 5, addr, 16);
    if (r < 0) return r;
    r = MemcpyD(cd, buf, 9, src, len);
    if (r < 0) return r;
    if (Libnet_CallRpc(cd, 0xE, buf, len + 0x24, 8) < 0) return -0x21E;
    if (p) *p = buf[1];
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034B050 */

/* merge_units: begin func_0034B138 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

NET_RPC2(sceInetAbort, 0xF)
#undef Libnet_CallRpc /* merge_units */
/* merge_units: end func_0034B138 */

/* merge_units: begin func_0034B180 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */


#define NET_RPC_IO(name, fno) int name(void *cd, int *buf, int a, int b, void *data, int len) { int r; buf[0] = a; buf[1] = b; buf[2] = len; r = MemcpyD(cd, buf, 3, data, len); if (r < 0) return r; if (Libnet_CallRpc(cd, fno, buf, len + 12, len + 12) < 0) return -0x21E; r = MemcpyS(cd, data, buf, 3, len); if (r < 0) return r; return buf[0]; }
#define NET_RPC_LIST(name, fno, esz) int name(void *cd, int *buf, void *dst, int n) { int r; buf[0] = n; if (Libnet_CallRpc(cd, fno, buf, 4, n * esz + 4) < 0) return -0x21E; if (buf[0] < 0) return buf[0]; r = MemcpyS(cd, dst, buf, 1, buf[0] * esz); if (r < 0) return r; return buf[0]; }
NET_RPC_IO(sceInetControl, 0x13)
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034B180 */

/* merge_units: begin func_0034B230 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */
NET_RPC_LIST(sceInetGetInterfaceList, 8, 4)
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034B230 */

/* merge_units: begin func_0034B2C0 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */
NET_RPC_IO(sceInetInterfaceControl, 9)
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034B2C0 */

/* merge_units: begin func_0034B370 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */
NET_RPC_LIST(sceInetGetRoutingTable, 0xA, 72)
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034B370 */

/* merge_units: begin func_0034B410 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */

NET_RPC_LIST(sceInetGetNameServers, 0xB, 16)
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034B410 */

/* merge_units: begin func_0034B4A0 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

NET_RPC1(sceInetChangeThreadPriority, 0xC)
#undef Libnet_CallRpc /* merge_units */
/* merge_units: end func_0034B4A0 */

/* merge_units: begin func_0034B4E8 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */

int sceInetGetLog(void *cd, unsigned int *buf, void *dst, int len, int x)
{
    int r;
    buf[0] = len; buf[1] = x;
    if (Libnet_CallRpc(cd, 0x11, buf, 8, len + 4) < 0) return -0x21E;
    r = MemcpyS(cd, dst, buf, 1, len);
    if (r < 0) return r;
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034B4E8 */

/* merge_units: begin func_0034B580 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

NET_RPC0(sceInetAbortLog, 0x10)
#undef Libnet_CallRpc /* merge_units */
/* merge_units: end func_0034B580 */

/* merge_units: begin func_0034B5C0 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

NET_RPC1(sceInetCtlUpInterface, 0x32)
#undef Libnet_CallRpc /* merge_units */
/* merge_units: end func_0034B5C0 */

/* merge_units: begin func_0034B608 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

NET_RPC1(sceInetCtlDownInterface, 0x33)
#undef Libnet_CallRpc /* merge_units */
/* merge_units: end func_0034B608 */

/* merge_units: begin func_0034B650 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

NET_RPC1(sceInetCtlSetAutoMode, 0x34)
#undef Libnet_CallRpc /* merge_units */
/* merge_units: end func_0034B650 */

/* merge_units: begin func_0034B698 */
#if 0 /* merge_units */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#endif /* merge_units */
#define Libnet_CallRpc(a0, a1, a2, a3, a4) (Libnet_CallRpc((NetCd_7A8 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
#endif /* merge_units */
#define MemcpyD(a0, a1, a2, a3, a4) (MemcpyD((NetCd_828 *)(a0), (char *)(a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
#endif /* merge_units */
#define MemcpyS(a0, a1, a2, a3, a4) (MemcpyS((NetCd_880 *)(a0), (a1), (char *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);
#endif /* merge_units */
#define StrcpyS(a0, a1, a2, a3) (StrcpyS((a0), (a1), (char *)(a2), (a3))) /* merge_units */

int sceInetCtlGetState(void *cd, unsigned int *buf, unsigned int a, unsigned int *p)
{
    buf[0] = a;
    if (p) buf[1] = *p; else buf[1] = 0;
    if (Libnet_CallRpc(cd, 0x35, buf, 8, 8) < 0) return -0x21E;
    if (p) *p = buf[1];
    return buf[0];
}
#undef Libnet_CallRpc /* merge_units */
#undef MemcpyD /* merge_units */
#undef MemcpyS /* merge_units */
#undef StrcpyS /* merge_units */
/* merge_units: end func_0034B698 */
