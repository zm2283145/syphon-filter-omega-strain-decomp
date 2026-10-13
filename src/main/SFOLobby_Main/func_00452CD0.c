typedef struct {
    int f0;
    int f4;
    void* f8;
    int fC;
    int f10;
    void* f14;
    int f18;
} Req1C;

typedef struct {
    int w[6];
} Res18;

typedef struct {
    char a[0x40];
    char b[0x40];
} Buf80;

typedef struct {
    void* f0;
    void* f4;
    void* f8;
    void* fC;
    int f10;
} Cb14;

typedef struct {
    char pad0[0x24C];
    int f24C;
    char pad250[0x1EA8 - 0x250];
    int f1EA8;
    char pad1EAC[0x1F3C - 0x1EAC];
    char buf1F3C[0x40];
    char pad1F7C[0x23D6 - 0x1F7C];
    unsigned char b23D6;
    char pad23D7[0x2409 - 0x23D7];
    unsigned char b2409;
    char pad240A[0x2550 - 0x240A];
    void (*cb2550)(int, int);
    char pad2554[0x2564 - 0x2554];
    unsigned char b2564;
    void* p2568;
    int f256C;
} Net;

extern void* memset(void*, int, unsigned int);
extern void func_0042B000(void);
extern void func_0042AFC0(void);
extern void func_002E9480(Req1C*);
extern void func_002E94E0(Req1C*, Res18*);
extern void func_002F96B8(void*, void*);
extern int func_00476998(void);
extern void func_00127DB8(int);
extern int Random_Next(void);
extern int func_00468630(Cb14*, int*);
extern void func_00352C30(void*);
extern void func_00445F90(void);
extern void func_00447C70(void);
extern void func_00446640(void);
extern void func_00447B90(void);
extern void func_00447200(void);
extern int D_00572538;
extern double func_0011C7A0(int);
extern double SoftFloat_FloatToDouble(float);
extern double func_0011C268(double, double);
extern double func_0011C200(double, double);
extern int func_0011C858(double);
extern char D_004C0FB0[];

int func_00452CD0(Net* s)
{
    Req1C req;
    Res18 res;
    Buf80 buf;
    Cb14 cb;
    int h;
    int x;

    func_0042B000();
    memset(&req, 0, sizeof(req));
    memset(&res, 0, sizeof(res));
    func_002E9480(&req);
    memset(&buf, 0, sizeof(buf));
    s->b2409 = 1;
    if (s->cb2550 != 0) {
        s->cb2550(0, 0);
    }
    s->b2409 = 0;
    if (!s->b23D6) {
        func_002F96B8(buf.a, buf.b);
    }
    req.f4 = func_00476998();
    req.f8 = s->b23D6 ? 0 : &buf;
    x = D_00572538;
    func_00127DB8(func_0011C858(func_0011C200(func_0011C7A0(x), func_0011C268(0.0625, SoftFloat_FloatToDouble((float)x)))));
    req.fC = Random_Next() % 1000 + 6000;
    req.f14 = func_00445F90;
    req.f10 = 1;
    req.f18 = 0;
    func_002E94E0(&req, &res);
    func_0042AFC0();
    memset(&cb, 0, sizeof(cb));
    memset(&h, 0, sizeof(h));
    cb.f0 = func_00447C70;
    cb.f4 = func_00446640;
    cb.f8 = func_00447B90;
    cb.fC = func_00447200;
    cb.f10 = 30000;
    s->f24C = func_00468630(&cb, &h);
    if (s->f24C == -0x13) {
        s->f24C = 0;
    }
    if (s->f24C != 0) {
        if (s->b2564 != 5) {
            s->b2564 = 0x10;
            s->p2568 = D_004C0FB0;
            s->f256C = 0x3AF;
        }
        return 0;
    }
    memset(s->buf1F3C, 0, sizeof(s->buf1F3C));
    if (!s->b23D6) {
        func_00352C30(s->buf1F3C);
    }
    s->f1EA8 = func_00476998();
    return 1;
}




