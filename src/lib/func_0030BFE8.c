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
int func_002F5C98(void* p, char* addr, unsigned short port, Opt_30BFE8* o);
int func_00310C30(void* h);
int func_002F5DB0(void* p);
int Socket_WriteConnected(void* p, char* buf, unsigned short len, unsigned short* out);
void* memset(void* d, int c, unsigned int n);
int sprintf(char* d, const char* fmt, ...);
int strlen(const char* s);

int func_0030BFE8(Conn_30BFE8* c, int flags, char* body)
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
    if (func_002F5C98(c->req, addr, port, &o) != 0) {
        func_00310C30(c->req->h);
        return 5;
    }
    sprintf(c->req->buf, D_004AFB78, c->req->host, addr, port, strlen(body) + 0x11C, body);
    if (Socket_WriteConnected(c->req->p0, c->req->buf, strlen(c->req->buf), &written) != 0
        || strlen(c->req->buf) != written) {
        func_002F5DB0(c->req->p0);
        func_00310C30(c->req->h);
        return 8;
    }
    return 0;
}



