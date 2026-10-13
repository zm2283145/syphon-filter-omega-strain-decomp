typedef struct {
    void* p0;
    void* h;
    int flags;
    char pad[0x1024 - 0xC];
    int status;
    char pad1028[0x2048 - 0x1028];
    void (*cb)(void* c, int r, int flags);
} Req_30C418;

typedef struct {
    char pad[0x50];
    int f50;
    int pad54;
    Req_30C418* req;
} Conn_30C418;

typedef struct { int flags; char rest[0x1300]; } Blob_30C418;

extern char D_0049134D;
extern int D_00491354;
extern char D_004AFF28[];
extern Blob_30C418 D_00529980;

int func_0030BC98(Conn_30C418* c, unsigned char* ok);
int func_00310C90(void* h, char* name, int a, int b);
int func_00310D20(void* h, Blob_30C418** out);
int func_00310C30(void* h);
void func_002F5DB0(void* p);
void* memset(void* d, int c, unsigned int n);

int func_0030C418(Conn_30C418* c)
{
    unsigned char ok;
    int r;
    Req_30C418* q;

    ok = 0;
    r = func_0030BC98(c, &ok);
    if (r != 0 || ok != 0) {
    q = c->req;
    if (q->status == 200 && ok) {
        Blob_30C418* v = 0;
        if (func_00310C90(q->h, D_004AFF28, 0, 1) == 0 && func_00310D20(c->req->h, &v) == 0) {
            D_00529980 = *v;
            c->req->flags = D_00529980.flags;
        }
    }
    D_0049134D = 1;
    D_00491354 = r;
    func_00310C30(c->req->h);
    c->req->h = 0;
    func_002F5DB0(c->req->p0);
    c->req->p0 = 0;
    c->req->cb(c, r, c->req->flags);
    c->req->cb = 0;
    memset(&c->req->status, 0, 0x100C);
    c->f50 = 0;
    }
    return r;
}

