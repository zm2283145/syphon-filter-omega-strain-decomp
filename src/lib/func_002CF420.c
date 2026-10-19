extern short D_0048C414;
extern int D_0048C404;
extern int D_0048C3D8;
extern char D_004AD2B8[];
extern int printf(const char *, ...);
extern void func_002EA5B0(void *msg);
extern void func_002CEBA0(void *cb);
extern int func_002EA648(void *msg, void *resp);
extern void func_002D0E28(void);

typedef struct {
    char hdr[8];
    char name[0x10];
    int f18;
    char pad1C[0x18];
    int f34;
    char pad38[0x64];
} ConnInfo;

typedef struct {
    ConnInfo info;
    void *cb;
} ConnReq;

typedef struct {
    int f0;
    int f4;
    ConnInfo info;
    void *cb;
    char pad[0x130 - 0xA8];
} ConnMsg;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} ConnResp;

int Medius_ConnectServer(ConnReq *req, int *status)
{
    ConnMsg msg;
    ConnResp resp;
    int r;

    if (D_0048C414 != 1) return -0xC;
    func_002EA5B0(&msg);
    msg.info = req->info;
    msg.f4 = D_0048C404;
    if (req->cb) {
        func_002CEBA0(req->cb);
        msg.cb = func_002D0E28;
    } else {
        func_002CEBA0(0);
    }
    r = func_002EA648(&msg, &resp);
    if (r) {
        printf(D_004AD2B8, req->info.name, req->info.f18, req->info.f34, r);
        *status = -2;
        return -2;
    }
    if (req->cb == 0) {
        D_0048C3D8 = resp.f8;
        *status = 0;
    }
    return 0;
}
