/*
 * lib/medius: 2 files, 0030C418-0030C5E8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0030C418 */
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
/* merge_units: end func_0030C418 */

/* merge_units: begin func_0030C5E8 */
typedef struct {
    void* p0;
    void* h;
    int flags;
    char pad[0x1024 - 0xC];
    int status;
    char pad1028[0x204C - 0x1028];
    void (*cb)(void* c, int r, int flags);
} Req_30C5E8;

typedef struct {
    char pad[0x50];
    int f50;
    int pad54;
    Req_30C5E8* req;
} Conn_30C5E8;

extern char D_0049134E;
extern char D_0049134F;
extern int D_00491358;
extern int D_0049135C;
extern int D_0052AC88;
extern int D_0052AC90;

#if 0 /* merge_units */
int func_0030BC98(Conn_30C5E8* c, unsigned char* ok);
#endif /* merge_units */
#define func_0030BC98(a0, a1) (func_0030BC98((Conn_30C418 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int func_00310D20(void* h, int** out);
#endif /* merge_units */
#define func_00310D20(a0, a1) (func_00310D20((a0), (Blob_30C418 * *)(a1))) /* merge_units */


int func_0030C5E8(Conn_30C5E8* c)
{
    unsigned char ok;
    int r;
    Req_30C5E8* q;

    ok = 0;
    r = func_0030BC98(c, &ok);
    if (r != 0 || ok != 0) {
    q = c->req;
    if (q->status == 200 && ok) {
        if (q->flags & 0x1000) {
            int* v = 0;
            if (func_00310C90(q->h, D_004AFF28, 0, 1) == 0 && func_00310D20(c->req->h, &v) == 0) {
                D_0052AC88 = *v;
                D_0049134E = 1;
                D_00491358 = r;
            }
        } else if (q->flags & 0x800) {
            int* v = 0;
            if (func_00310C90(q->h, D_004AFF28, 0, 1) == 0 && func_00310D20(c->req->h, &v) == 0) {
                D_0052AC90 = *v;
                D_0049134F = 1;
                D_0049135C = r;
            }
        }
    }
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
#undef func_0030BC98 /* merge_units */
#undef func_00310D20 /* merge_units */
/* merge_units: end func_0030C5E8 */
