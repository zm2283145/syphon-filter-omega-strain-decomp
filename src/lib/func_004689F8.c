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
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00497CF0;
void func_002EA5B0(ConnParam*);
int func_002EA648(ConnParam*, ConnResult*);
void func_00468470(int);
void func_00468420(void);
void func_00468490(int, int);

int func_004689F8(ConnReq* req, ConnOut* out)
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
    func_002EA5B0(&p);
    p.a = req->a;
    p.arg = req->arg;
    if (req->cb) {
        func_00468470(req->cb);
        p.cb = func_00468420;
    } else {
        func_00468470(0);
    }
    p.f8 = req->f8;
    p.fc = req->fc;
    p.b = req->b;
    ret = func_002EA648(&p, &r);
    if (ret) {
        D_00497CF0 = ret;
        out->id = r.id;
        out->err = -2;
        func_00468490(-2, ret);
        return -2;
    }
    if (!req->cb) D_00497CC4 = r.id;
    out->id = r.id;
    out->err = 0;
    return ret;
}




