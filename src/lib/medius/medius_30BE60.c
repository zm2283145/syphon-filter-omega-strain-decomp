/*
 * lib/medius: 3 files, 0030BE60-0030C1B8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0030BE60 */
typedef struct {
    int sock;
    char pad4[4];
    unsigned int kind;
    char padC[4];
    char timer[8];
    char hdr[0xA24 - 0x18];
    char service[0x2070 - 0xA24];
    char resp[0x800];
} UpnpReq;
typedef struct {
    char pad0[0x58];
    UpnpReq *req;
} UpnpObj;
extern int rt_comm_receive_from(int sock, void *from, unsigned short *fromlen, char *buf, int size, unsigned short *len);
extern int func_0030B760(char *resp, char *hdr);
extern int rt_time_elapsed(void *timer, unsigned int *ms);
extern int Libc_Strncmp(const char *a, const char *b, unsigned int n);
extern char D_004AFAB0[];
extern char D_004AFAE0[];
extern char D_004AFB18[];
extern char D_004AFB48[];

/* Polls the UPnP discovery reply; sets *done and returns 0 when the expected service answered. */
int func_0030BE60(UpnpObj *o, unsigned char *done)
{
    char from[16];
    unsigned short fromlen = 0;
    unsigned short len = 0;
    unsigned int ms;
    char *svc;

    if (rt_comm_receive_from(o->req->sock, from, &fromlen, o->req->resp, 0x800, &len) != 0) {
        *done = 1;
        return 5;
    }
    if (len != 0) {
        *done = 1;
        o->req->resp[len] = 0;
        len = func_0030B760(o->req->resp, o->req->hdr);
        if (len == 200) {
            switch (o->req->kind) {
            case 0x20:
                if (Libc_Strncmp(D_004AFAB0, o->req->service, 0x200) != 0) return 10;
                break;
            case 0x40:
                if (Libc_Strncmp(D_004AFAE0, o->req->service, 0x200) != 0) return 10;
                break;
            case 0x1000:
                if (Libc_Strncmp(D_004AFB18, o->req->service, 0x200) != 0) return 10;
                break;
            case 0x800:
                if (Libc_Strncmp(D_004AFB48, o->req->service, 0x200) != 0) return 10;
                break;
            default:
                return 13;
            }
        } else {
            return 11;
        }
    } else {
        rt_time_elapsed(o->req->timer, &ms);
        if (ms >= 5001) {
            *done = 1;
            return 6;
        }
    }
    return 0;
}
/* merge_units: end func_0030BE60 */

/* merge_units: begin func_0030BFE8 */
typedef struct {
    void* p0;
    void* h;
    char pad8[0x2030 - 0x8];
    char b2030;
    char b2031;
    char pad2032[6];
    int f2038;
    char pad203C[0x2070 - 0x203C];
    char buf[0x800];
    char host[0x100];
} Req_30BFE8;

typedef struct {
    char pad[0x58];
    Req_30BFE8* req;
    int f5C;
} Conn_30BFE8;

typedef struct { int flags; } Blob_30BFE8;
typedef struct { int a; int b; int c; } Opt_30BFE8;

extern Blob_30BFE8 D_00529980;
extern char D_004AFB78[];

int func_0030BB48(Blob_30BFE8* d, int flags, char* buf);
int func_0030B5F0(char* url, char* host, char* addr, unsigned short* port);
int func_00310988(void** h, int n, int x);
int rt_comm_create(void* p, char* addr, unsigned short port, Opt_30BFE8* o);
int func_00310C30(void* h);
int rt_comm_destroy(void* p);
int rt_comm_send(void* p, char* buf, unsigned short len, unsigned short* out);
void* memset(void* d, int c, unsigned int n);
int sprintf(char* d, const char* fmt, ...);
int strlen(const char* s);

int UPnP_SendQueryStateVariable(Conn_30BFE8* c, int flags, char* body)
{
    Opt_30BFE8 o;
    char addr[16];
    unsigned short port;
    unsigned short written;
    int r;

    c->req->b2030 = 0;
    c->req->b2031 = 0;
    c->req->f2038 = 0;
    r = func_0030BB48(&D_00529980, flags, c->req->buf);
    if (r != 0) return r;
    r = func_0030B5F0(c->req->buf, c->req->host, addr, &port);
    if (r != 0) return r;
    if (!(flags & D_00529980.flags)) return 0xC;
    if (flags != 0x1000 && !(flags & 0x800)) return 2;
    if (func_00310988(&c->req->h, 10, c->f5C) != 0 || c->req->h == 0) return 4;
    memset(&o, 0, 0xC);
    o.a = 0;
    o.b = 0x800;
    if (rt_comm_create(c->req, addr, port, &o) != 0) {
        func_00310C30(c->req->h);
        return 5;
    }
    sprintf(c->req->buf, D_004AFB78, c->req->host, addr, port, strlen(body) + 0x11C, body);
    if (rt_comm_send(c->req->p0, c->req->buf, strlen(c->req->buf), &written) != 0
        || strlen(c->req->buf) != written) {
        rt_comm_destroy(c->req->p0);
        func_00310C30(c->req->h);
        return 8;
    }
    return 0;
}
/* merge_units: end func_0030BFE8 */

/* merge_units: begin func_0030C1B8 */
typedef struct {
    void* p0;
    void* h;
    int flags;
    char pad0C[0x2030 - 0xC];
    char b2030;
    char b2031;
    char pad2032[6];
    int f2038;
    char pad203C[0x2070 - 0x203C];
    char buf[0x800];
    char host[0x400];
    char path[0x200];
} Req_30C1B8;

typedef struct {
    char pad[0x58];
    Req_30C1B8* req;
    int f5C;
} Conn_30C1B8;

typedef struct { int flags; } Blob_30C1B8;
typedef struct { int a; int b; int c; } Opt_30C1B8;

#if 0 /* merge_units */
extern Blob_30C1B8 D_00529980;
#endif /* merge_units */
#define D_00529980 (*(Blob_30C1B8*)&D_00529980) /* merge_units */

extern char D_004AFD48[];
extern char D_004AFD58[];
extern char D_004AFD70[];

#if 0 /* merge_units */
int func_0030BB48(Blob_30C1B8* d, int flags, char* buf);
#endif /* merge_units */
#define func_0030BB48(a0, a1, a2) (func_0030BB48((Blob_30BFE8 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int rt_comm_create(void* p, char* addr, unsigned short port, Opt_30C1B8* o);
#endif /* merge_units */
#define rt_comm_create(a0, a1, a2, a3) (rt_comm_create((a0), (a1), (a2), (Opt_30BFE8 *)(a3))) /* merge_units */

char* strncpy(char* d, const char* s, unsigned int n);

int UPnP_SendSoapAction(Conn_30C1B8* c, char* action, char* args)
{
    Opt_30C1B8 o;
    char addr[16];
    unsigned short port;
    unsigned short written;
    int r;
    int n1, n2;

    c->req->b2030 = 1;
    c->req->b2031 = 0;
    c->req->f2038 = 0;
    r = func_0030BB48(&D_00529980, c->req->flags, c->req->buf);
    if (r != 0) return r;
    r = func_0030B5F0(c->req->buf, c->req->host, addr, &port);
    if (r != 0) return r;
    if (!(c->req->flags & D_00529980.flags)) return 0xC;
    if (c->req->flags != 0x1000 && !(c->req->flags & 0x800)) return 2;
    if (func_00310988(&c->req->h, 0xB, c->f5C) != 0 || c->req->h == 0) return 4;
    if (c->req->flags == 0x1000)
        strncpy(c->req->path, D_004AFD48, 0x200);
    else
        strncpy(c->req->path, D_004AFD58, 0x200);
    memset(&o, 0, 0xC);
    o.a = 0;
    o.b = 0x800;
    if (rt_comm_create(c->req, addr, port, &o) != 0) {
        func_00310C30(c->req->h);
        return 5;
    }
    n1 = strlen(args) + 0xD7;
    n2 = strlen(c->req->path) + strlen(action) * 2;
    sprintf(c->req->buf, D_004AFD70, c->req->host, addr, port,
            n1 + n2,
            c->req->path, action, action, c->req->path, args, action);
    if (rt_comm_send(c->req->p0, c->req->buf, strlen(c->req->buf), &written) != 0
        || strlen(c->req->buf) != written) {
        rt_comm_destroy(c->req->p0);
        func_00310C30(c->req->h);
        return 8;
    }
    return 0;
}
#undef D_00529980 /* merge_units */
#undef func_0030BB48 /* merge_units */
#undef rt_comm_create /* merge_units */
/* merge_units: end func_0030C1B8 */
