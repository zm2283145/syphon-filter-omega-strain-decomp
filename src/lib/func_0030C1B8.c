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

extern Blob_30C1B8 D_00529980;
extern char D_004AFD48[];
extern char D_004AFD58[];
extern char D_004AFD70[];

int func_0030BB48(Blob_30C1B8* d, int flags, char* buf);
int func_0030B5F0(char* url, char* host, char* addr, unsigned short* port);
int func_00310988(void** h, int n, int x);
int func_002F5C98(void* p, char* addr, unsigned short port, Opt_30C1B8* o);
int func_00310C30(void* h);
int func_002F5DB0(void* p);
int Socket_WriteConnected(void* p, char* buf, unsigned short len, unsigned short* out);
void* memset(void* d, int c, unsigned int n);
char* strncpy(char* d, const char* s, unsigned int n);
int sprintf(char* d, const char* fmt, ...);
int strlen(const char* s);

int func_0030C1B8(Conn_30C1B8* c, char* action, char* args)
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
    if (func_002F5C98(c->req, addr, port, &o) != 0) {
        func_00310C30(c->req->h);
        return 5;
    }
    n1 = strlen(args) + 0xD7;
    n2 = strlen(c->req->path) + strlen(action) * 2;
    sprintf(c->req->buf, D_004AFD70, c->req->host, addr, port,
            n1 + n2,
            c->req->path, action, action, c->req->path, args, action);
    if (Socket_WriteConnected(c->req->p0, c->req->buf, strlen(c->req->buf), &written) != 0
        || strlen(c->req->buf) != written) {
        func_002F5DB0(c->req->p0);
        func_00310C30(c->req->h);
        return 8;
    }
    return 0;
}

