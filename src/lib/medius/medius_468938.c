/*
 * lib/medius: 3 files, 00468938-004689F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00468938 */
extern void *memset(void *, int, unsigned int);
extern char D_00497CD0[];
extern short D_00497CC0;
extern int D_00497CC4;
extern void MediusDisconnect(void);
extern int NetClose(void);
int MediusClose(void)
{
    memset(D_00497CD0, 0, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 >= 0) MediusDisconnect();
    if (NetClose()) return -4;
    D_00497CC0 = 0;
    return 0;
}
/* merge_units: end func_00468938 */

/* merge_units: begin func_004689B0 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int memset(int , int, int);
#endif /* merge_units */
#define memset(a0, a1, a2) ((int)memset((void *)(a0), (a1), (unsigned int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int D_00497CD0;
#endif /* merge_units */
#define D_00497CD0 (*(int*)&D_00497CD0) /* merge_units */


int MediusCloseBare(void) {
    int var_v0;

    memset(&D_00497CD0, 0, 0x11);
    if (!(D_00497CC0 == 1)) return -0xF;
    D_00497CC0 = 0;
    return 0;
}
#undef memset /* merge_units */
#undef D_00497CD0 /* merge_units */
/* merge_units: end func_004689B0 */

/* merge_units: begin func_004689F8 */
typedef struct { int d[0x27]; } BlkA;
typedef struct { int d[0x15]; } BlkB;
typedef struct {
    BlkA a;
    BlkB b;
    int arg;
    int cb;
    int f8;
    int fc;
} ConnReq;
typedef struct {
    int pad0;
    int arg;
    BlkA a;
    void (*cb)(void);
    int padA8[3];
    int f8;
    int padB8;
    int fc;
    int padC0[3];
    BlkB b;
    int pad120[4];
} ConnParam;
typedef struct { int pad[2]; int id; int pad2; } ConnResult;
typedef struct { int id; int err; } ConnOut;
extern int D_00497CF0;
void NetSetDefaultConnectParams(ConnParam*);
int NetConnect(ConnParam*, ConnResult*);
void MediusSetClientConnectCallback(int);
void MediusLocalConnectCallback(void);
void MediusClearClientConnectCallback(int, int);

int MediusConnect(ConnReq* req, ConnOut* out)
{
    ConnParam p;
    ConnResult r;
    int ret;

    if (D_00497CC0 != 1) {
        out->err = -15;
        out->id = -1;
        return -15;
    }
    if (D_00497CC4 >= 0) {
        out->err = -17;
        out->id = -1;
        return -17;
    }
    NetSetDefaultConnectParams(&p);
    p.a = req->a;
    p.arg = req->arg;
    if (req->cb) {
        MediusSetClientConnectCallback(req->cb);
        p.cb = MediusLocalConnectCallback;
    } else {
        MediusSetClientConnectCallback(0);
    }
    p.f8 = req->f8;
    p.fc = req->fc;
    p.b = req->b;
    ret = NetConnect(&p, &r);
    if (ret) {
        D_00497CF0 = ret;
        out->id = r.id;
        out->err = -2;
        MediusClearClientConnectCallback(-2, ret);
        return -2;
    }
    if (!req->cb) D_00497CC4 = r.id;
    out->id = r.id;
    out->err = 0;
    return ret;
}
/* merge_units: end func_004689F8 */
