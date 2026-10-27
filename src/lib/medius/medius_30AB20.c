/*
 * lib/medius: 14 files, 0030AB20-0030BB48
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0030AB20 */
typedef enum { TyEnum_0 } TyEnum;
typedef struct { unsigned char kind; unsigned char id; unsigned short pad; TyEnum val; int pad2; } ScfHdr;
typedef struct { int sock; char pad[0x44]; unsigned char b48; } ScfSock;
typedef struct { int f0; int f4; int addr[4]; unsigned short port; char pad[0x5A]; int f74; } ScfPeer;
extern void *memset(void *d, int c, unsigned int n);
extern int rt_comm_send_to(int sock, void *addr, unsigned short port, void *data, int len, unsigned short *sent);
int rt_udp_send_reset(ScfSock *s, ScfPeer *e)
{
    ScfHdr hdr;
    unsigned short sent = 0;
    int ret = 2;
    if (s == 0) return ret;
    ret = 1;
    if (e == 0) return ret;
    memset(&hdr, 0, 12);
    hdr.id = s->b48;
    hdr.kind = 8;
    hdr.val = e->f74;
    rt_comm_send_to(s->sock, e->addr, e->port, &hdr, 12, &sent);
    return 0;
}
/* merge_units: end func_0030AB20 */

/* merge_units: begin func_0030ABA8 */
typedef struct { unsigned char kind; unsigned char id; unsigned short pad; int val; int pad2; } ScfHdr_0030ABA8;
int rt_udp_reset(ScfSock *s, void *addr, unsigned short port, int val)
{
    ScfHdr_0030ABA8 hdr;
    unsigned short sent = 0;
    int ret = 2;
    if (s == 0) return ret;
    memset(&hdr, 0, 12);
    hdr.id = s->b48;
    hdr.kind = 8;
    hdr.val = val;
    rt_comm_send_to(s->sock, addr, port, &hdr, 12, &sent);
    return 0;
}
/* merge_units: end func_0030ABA8 */

/* merge_units: begin func_0030AC40 */
typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr_0030AC40;
typedef struct { unsigned char b[4]; } ScfU32u;
typedef struct { unsigned char flags; unsigned char pad[7]; ScfU32u seq; } ScfRxHdr;
typedef struct { int sock; char pad[0x44]; int b48; } ScfSock_0030AC40;
extern void *memcpy(void *d, const void *s, unsigned int n);
extern int rt_udp_buffer_data_for_send(ScfPeer *e, ScfHdr_0030AC40 *h, void *data, int len);

int rt_udp_send_ack(ScfSock_0030AC40 *s, ScfPeer *e, ScfRxHdr *p)
{
    ScfHdr_0030AC40 hdr;
    unsigned char ack[5];
    memset(&hdr, 0, 12);
    hdr.kind = 0x20;
    hdr.id = s->b48;
    hdr.val = e->f74;
    hdr.len = 5;
    ack[0] = p->flags;
    memcpy(&ack[1], &p->seq, 4);
    return rt_udp_buffer_data_for_send(e, &hdr, ack, 5);
}
/* merge_units: end func_0030AC40 */

/* merge_units: begin func_0030ACD8 */
typedef struct { unsigned char b[12]; } ScfAddr12;
typedef struct { union { unsigned int w; unsigned char flags; } u; int val; int seq; } ScfHdr_0030ACD8;
typedef struct { unsigned int type; char pad[0x30]; int list; char pad2[0x48]; unsigned int f80; unsigned int f84; char pad3[0x8]; } ScfPeer_0030ACD8;
typedef struct { int sock; ScfPeer_0030ACD8 *ents; } ScfSock_0030ACD8;
extern int rt_list_buf_get_head(int *list, void **node);
extern unsigned int rt_list_buf_get_data_size(void *node);
extern char *rt_list_buf_get_data_ptr(void *node);
extern void *rt_list_buf_get_next(void *node);

int rt_udp_is_duplicate_packet(ScfSock_0030ACD8 *s, ScfPeer_0030ACD8 *e, ScfHdr_0030ACD8 *p, unsigned char *dup)
{
    ScfHdr_0030ACD8 hd;
    void *node = 0;
    int ret = 1;
    if (dup == 0) return ret;
    *dup = 0;
    if (s == 0) return ret;
    if (e == 0) return ret;
    if (p == 0) return ret;
    if (e->type != 0) {
        if ((p->u.w & 6) == 6 || (p->u.flags & 4)) {
            if ((int)(e->f84 - p->seq) >= 0 && e->f84 != 0) {
                *dup = 1;
            } else {
                if (rt_list_buf_get_head(&e->list, &node) != 0) return 10;
                while (node != 0) {
                    if (rt_list_buf_get_data_size(node) != 0) {
                        *(ScfAddr12 *)&hd = *(ScfAddr12 *)rt_list_buf_get_data_ptr(node);
                        if (((hd.u.w & 6) == 6 || (hd.u.flags & 4)) && hd.seq == p->seq) {
                            *dup = 1;
                            break;
                        }
                    }
                    node = rt_list_buf_get_next(node);
                }
            }
        } else if (p->u.flags & 2) {
            if ((int)(e->f80 - p->seq) >= 0) {
                *dup = 1;
                if (e->f80 <= 0x7FFFFFFE && p->seq < 0) {
                    e->f80 = p->seq;
                    *dup = 0;
                }
            }
        }
    }
    return 0;
}
/* merge_units: end func_0030ACD8 */

/* merge_units: begin func_0030AE88 */
typedef struct {
    char pad[0x5C];
    int timer[2];
    int pending;
    unsigned int rttvar;
    unsigned int srtt;
    unsigned int rto;
} RtUdpRtt;
extern void rt_time_elapsed(int *timer, unsigned int *elapsed);
int rt_udp_calculate_rto(void *ctx, RtUdpRtt *r, unsigned char flags, int seq)
{
    unsigned int elapsed;
    unsigned int srtt, rttvar, rto, v;
    int ret = 1;
    if (ctx == 0) return ret;
    if (r == 0) return ret;
    if (((flags & 6) == 6 || (flags & 4)) && r->pending != 0 && seq == r->pending) {
        rt_time_elapsed(r->timer, &elapsed);
        srtt = r->srtt;
        rttvar = r->rttvar;
        if (srtt == 0) {
            srtt = elapsed;
            rttvar = elapsed >> 1;
        } else {
            rttvar = (rttvar * 3 + __builtin_abs(srtt - elapsed)) >> 2;
            srtt = (srtt * 7 + elapsed) >> 3;
        }
        v = rttvar;
        if (v == 0) v = 1;
        rto = srtt + v;
        r->srtt = srtt;
        r->rttvar = rttvar;
        r->pending = 0;
        if (rto > 500) rto = 500;
        r->rto = rto;
    }
    return 0;
}
/* merge_units: end func_0030AE88 */

/* merge_units: begin func_0030AF68 */
typedef struct { int sock; char pad[0x20]; void *buf1; void *buf2; char pad2[0xC]; unsigned int mtu; char pad3[0xA]; unsigned short port; unsigned int idx; } ScfSock_0030AF68;
typedef struct { int a; unsigned int size; int c; } ScfSockOpt;
extern int rt_memory_allocate_init_zero(void *out, unsigned long n);
extern int rt_comm_create(int *sock, int a, unsigned short port, ScfSockOpt *opt);
extern int rt_comm_startup(void);
extern int rt_comm_get_local_port(int sock, unsigned short *port);
extern int D_00491310;
extern unsigned short D_00491314;
extern void *D_00491318;
extern void *D_0049131C;
extern ScfSock_0030AF68 *D_00529860[8];

int rt_udp_create_shared_channel_data(ScfSock_0030AF68 *s)
{
    ScfSockOpt opt;
    int r;
    if (s->idx < 8) {
        if (s->mtu >= 0x59F) return 1;
        if (D_00491310 == 0) {
            D_00491314 = s->port;
            if (rt_memory_allocate_init_zero(&D_00491318, 0x5AA) != 0) return 9;
            if (rt_memory_allocate_init_zero(&D_0049131C, 0x5AA) != 0) return 9;
            memset(D_00529860, 0, 0x20);
            memset(&opt, 0, 12);
            opt.size = 0x5AA;
            opt.a = 1;
            r = rt_comm_create(&D_00491310, 0, D_00491314, &opt);
            if (r == 5) {
                if (rt_comm_startup() != 0) return 16;
                if (rt_comm_create(&D_00491310, 0, D_00491314, &opt) != 0) return 16;
            } else if (r != 0) {
                return 16;
            }
            if (rt_comm_get_local_port(D_00491310, &D_00491314) != 0) return 16;
            s->port = D_00491314;
        }
        if (D_00529860[s->idx] == 0) {
            if (s->port != D_00491314) return 16;
            D_00529860[s->idx] = s;
            s->sock = D_00491310;
            s->buf1 = D_00491318;
            s->buf2 = D_0049131C;
        } else return 17;
    } else {
        if (s->mtu >= 0x59F) return 1;
        if (rt_memory_allocate_init_zero(&s->buf1, s->mtu + 12) != 0) return 9;
        if (rt_memory_allocate_init_zero(&s->buf2, s->mtu + 12) != 0) return 9;
        memset(&opt, 0, 12);
        opt.size = s->mtu + 12;
        opt.a = 1;
        r = rt_comm_create(&s->sock, 0, s->port, &opt);
        if (r == 5) {
            if (rt_comm_startup() != 0) return 16;
            if (rt_comm_create(&s->sock, 0, s->port, &opt) != 0) return 16;
        } else if (r != 0) {
            return 16;
        }
        if (rt_comm_get_local_port(s->sock, &s->port) != 0) return 16;
    }
    return 0;
}
/* merge_units: end func_0030AF68 */

/* merge_units: begin func_0030B220 */
typedef struct {
    int sock;
    char pad4[4];
    void *ext;
    char padC[0x18];
    void *buf1;
    void *buf2;
    char pad2C[0x1C];
    unsigned int idx;
} ScfSock_0030B220;
extern void rt_comm_destroy(int sock);
extern void rt_memory_free(void *pp);
extern void func_0030DED8(void *p);
extern void *D_00491320;
extern unsigned char D_00491324;
#if 0 /* merge_units */
extern ScfSock_0030B220 *D_00529860[8];
#endif /* merge_units */
#define D_00529860 ((ScfSock_0030B220 **)&D_00529860) /* merge_units */


/* Closes an RT UDP socket; the shared socket is torn down when its last user goes. */
int rt_udp_destroy_shared_channel_data(ScfSock_0030B220 *s)
{
    int last = 1;
    unsigned int i;

    if (s->idx < 8) {
        D_00529860[s->idx] = 0;
        for (i = 0; i < 8; i++) {
            if (D_00529860[i] != 0) last = 0;
        }
        if (last) {
            rt_comm_destroy(D_00491310);
            D_00491310 = 0;
            D_00491314 = 0;
            rt_memory_free(&D_00491318);
            D_00491318 = 0;
            rt_memory_free(&D_0049131C);
            D_0049131C = 0;
            if (D_00491320 != 0) {
                func_0030DED8(D_00491320);
                D_00491320 = 0;
                D_00491324 = 0;
            }
        }
    } else {
        rt_comm_destroy(s->sock);
        rt_memory_free(&s->buf1);
        rt_memory_free(&s->buf2);
        if (s->ext != 0) {
            func_0030DED8(s->ext);
            s->ext = 0;
        }
    }
    return 0;
}
#undef D_00529860 /* merge_units */
/* merge_units: end func_0030B220 */

/* merge_units: begin func_0030B338 */
typedef struct ScfSock_0030B338 ScfSock_0030B338;
typedef void (*ScfCb)(ScfSock_0030B338 *s, int ev, int a, int b, int user);
struct ScfSock_0030B338 {
    char pad0[0x45];
    unsigned char pending;
    char pad46[2];
    unsigned int idx;
    ScfCb cb;
    int user;
};
#if 0 /* merge_units */
extern ScfSock_0030B338 *D_00529860[8];
#endif /* merge_units */
#define D_00529860 ((ScfSock_0030B338 **)&D_00529860) /* merge_units */


/* Flushes pending notifications: fires each pending socket's callback with event -2. */
void rt_udp_uber_resolve_cb(int a0, int abort, int a2, int a3, int t0, ScfSock_0030B338 *s)
{
    unsigned int i;

    if (s == 0) return;
    if (s->idx < 8) {
        D_00491324 = 0;
        for (i = 0; i < 8; i++) {
            if (D_00529860[i] != 0 && D_00529860[i]->pending != 0) {
                D_00529860[i]->pending = 0;
                if (abort == 0)
                    D_00529860[i]->cb(s, -2, 5, 0, D_00529860[i]->user);
                else
                    D_00529860[i]->cb(s, -2, 5, 15, D_00529860[i]->user);
            }
        }
    } else {
        s->pending = 0;
        if (abort == 0)
            s->cb(s, -2, 5, 0, s->user);
        else
            s->cb(s, -2, 5, 15, s->user);
    }
}
#undef D_00529860 /* merge_units */
/* merge_units: end func_0030B338 */

/* merge_units: begin func_0030B468 */
/* strsep-style tokenizer: returns the current token and advances *sp past the next delimiter. */
char *func_0030B468(char **sp, const char *delim)
{
    char *s = *sp;
    const char *d;

    if (s == 0) return 0;
    if (delim == 0) return s;
    while (**sp != 0) {
        for (d = delim; *d != 0; d++) {
            if (**sp == *d) {
                **sp = 0;
                (*sp)++;
                return s;
            }
        }
        (*sp)++;
    }
    *sp = 0;
    return s;
}
/* merge_units: end func_0030B468 */

/* merge_units: begin func_0030B510 */
typedef unsigned int size_t;
extern unsigned char D_00499C70[];
#define isupper(c) ((D_00499C70 + 1)[(unsigned)(c)] & 1)
#define tolower(c) ({ int __x = (c); isupper(__x) ? (__x - 'A' + 'a') : __x; })
int func_0030B510(const char *s1, const char *s2, size_t n)
{
    if (n == 0)
        return 0;
    while (n-- != 0 && tolower(*s1) == tolower(*s2)) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}
/* merge_units: end func_0030B510 */

/* merge_units: begin func_0030B5F0 */
extern char *strncpy(char *d, const char *s, size_t n);
extern size_t strlen(const char *s);
extern long strtol(const char *s, char **end, int base);
extern char *func_0030B468(char **sp, const char *delim);
extern const char D_004AF990[];
#define isdigit(c) ((D_00499C70 + 1)[(int)(c)] & 4)

/* Splits "proto://host:port/path"-style URL text: copies the path to path, host to host, port to *port. */
int func_0030B5F0(char *url, char *path, char *host, unsigned short *port)
{
    char *rest = 0;
    int slashes = 0;
    unsigned int i = 0;
    char *p;
    char *tok;

    if (url == 0) return 2;
    if (path == 0) return 2;
    if (host == 0) return 2;
    if (port == 0) return 2;
    for (i = 0; i < strlen(url); i++) {
        p = url + i;
        if (*p == '/') {
            slashes++;
            if (slashes == 2) {
                rest = p + 1;
            } else if (slashes == 3) {
                strncpy(path, p + 1, 0x200);
                *p = 0;
                tok = func_0030B468(&rest, D_004AF990);
                if (!isdigit(*tok)) return 11;
                strncpy(host, tok, 0x10);
                if (rest != 0)
                    *port = strtol(rest, 0, 10);
                else
                    *port = 80;
            }
        }
    }
    return 0;
}
/* merge_units: end func_0030B5F0 */

/* merge_units: begin func_0030B760 */
const char D_004AF990[] = ":";
#define isspace(c) ((D_00499C70 + 1)[(int)(c)] & 8)
char *func_0012AC70(char *s, const char *delim);
long strtol(const char *s, char **end, int base);
int func_0030B510(const char *s1, const char *s2, size_t n);
char *func_0030B468(char **sp, const char *delim);
size_t strlen(const char *s);
char *strncpy(char *d, const char *s, size_t n);

typedef struct {
    int status;
    int maxage;
    int clen;
    char date[0x200];
    char usn[0x200];
    char ext[0x200];
    char location[0x200];
    char server[0x200];
    char st[0x200];
    char ctype[0x200];
    char clang[0x200];
} SsdpResp;

int func_0030B760(char *buf, SsdpResp *r)
{
    char *p = 0;
    const char *names[] = {
        "Cache-Control", "USN", "Location", "Server", "ST", "EXT", "Date",
        "Content-length", "Content-language", "Content-type", 0
    };
    int status = -1;
    int line = 0;
    char *tok;
    int i;

    tok = func_0012AC70(buf, "\r\n");
    while (tok) {
        if (line == 0) {
            if (func_0030B510(tok, "http/1.", 7) == 0) {
                p = tok + 9;
                status = (short)strtol(p, 0, 10);
                r->status = status;
                if (status != 200)
                    return status;
            } else {
                return status;
            }
        } else {
            p = tok;
            func_0030B468(&p, D_004AF990);
            while (isspace(*p))
                p++;
            for (i = strlen(tok); i > 0; i--) {
                if (isspace(tok[i]))
                    tok[i] = 0;
            }
            for (i = 0; names[i] && func_0030B510(names[i], tok, strlen(names[i])); i++)
                ;
            switch (i) {
            case 0:
                if (func_0030B510(func_0030B468(&p, "="), "max-age", 7) == 0)
                    r->maxage = strtol(p, 0, 10);
                break;
            case 1:
                strncpy(r->usn, p, 0x200);
                break;
            case 2:
                strncpy(r->location, p, 0x200);
                break;
            case 3:
                strncpy(r->server, p, 0x200);
                break;
            case 4:
                strncpy(r->st, p, 0x200);
                break;
            case 5:
                strncpy(r->ext, p, 0x200);
                break;
            case 6:
                strncpy(r->date, p, 0x200);
                break;
            case 7:
                r->clen = strtol(p, 0, 10);
                break;
            case 8:
                strncpy(r->clang, p, 0x200);
                break;
            case 9:
                strncpy(r->ctype, p, 0x200);
                break;
            }
        }
        tok = func_0012AC70(0, "\r\n");
        line++;
    }
    return status;
}
/* merge_units: end func_0030B760 */

/* merge_units: begin func_0030BA90 */
extern char D_004AFA98[];
#if 0 /* merge_units */
extern int func_0030B510(const char *a, const char *b, unsigned int n);
#endif /* merge_units */
#define func_0030B510(a0, a1, a2) (func_0030B510((a0), (a1), (size_t)(a2))) /* merge_units */

#if 0 /* merge_units */
extern char *strncpy(char *d, const char *s, unsigned int n);
#endif /* merge_units */
#define strncpy(a0, a1, a2) (strncpy((a0), (a1), (size_t)(a2))) /* merge_units */

extern char *Libc_Strncat(char *d, const char *s, unsigned int n);
int func_0030BA90(char *base, int kind, char *dst)
{
    char *src;
    if (base == 0) return 2;
    if (dst == 0) return 2;
    if (kind == 0x1000) src = base + 0x1004;
    else if (kind == 0x800) src = base + 0xC04;
    else return 2;
    if (func_0030B510(src, D_004AFA98, 4) == 0) {
        strncpy(dst, src, 0x800);
    } else {
        strncpy(dst, base + 4, 0x800);
        Libc_Strncat(dst, src, 0x800);
    }
    return 0;
}
#undef func_0030B510 /* merge_units */
#undef strncpy /* merge_units */
/* merge_units: end func_0030BA90 */

/* merge_units: begin func_0030BB48 */
#if 0 /* merge_units */
extern int func_0030B510(const char *a, const char *b, size_t n);
#endif /* merge_units */
#define func_0030B510(a0, a1, a2) (func_0030B510((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern char *Libc_Strncat(char *d, const char *s, size_t n);
#endif /* merge_units */
#define Libc_Strncat(a0, a1, a2) (Libc_Strncat((a0), (a1), (unsigned int)(a2))) /* merge_units */

extern int func_0030BA90(char *base, int kind, char *dst);

/* Resolves the relative URL for kind against the base URL into dst. */
int func_0030BB48(char *base, int kind, char *dst)
{
    char *src;
    int slashes;
    unsigned int i;

    if (kind == 0x1000) src = base + 0x1104;
    else if (kind == 0x800) src = base + 0xD04;
    else return 2;
    if (func_0030B510(src, D_004AFA98, 4) == 0) {
        strncpy(dst, src, 0x800);
        return 0;
    }
    if (func_0030B510(base + 4, D_004AFA98, 4) == 0) {
        strncpy(dst, base + 4, 0x800);
        Libc_Strncat(dst, src, 0x800);
        return 0;
    }
    func_0030BA90(base, kind, dst);
    slashes = 0;
    for (i = 0; i < strlen(dst); i++) {
        if (dst[i] == '/') {
            slashes++;
            if (slashes == 3) {
                strncpy(dst + i, src, 0x800 - i);
                break;
            }
        }
    }
    return 0;
}
#undef func_0030B510 /* merge_units */
#undef Libc_Strncat /* merge_units */
/* merge_units: end func_0030BB48 */
