#include "types.h"
typedef struct B48 { int w[12]; } B48;
typedef struct P8 { int a; int b; } P8;
typedef struct P64 { P8 p[8]; } P64;
typedef struct S17 { char c[17]; } S17;
typedef struct Info {
    int id;          /* 0x00 */
    B48 blk;         /* 0x04 */
    int f34;         /* 0x34 */
    P64 pairs;     /* 0x38 */
    S17 s1;          /* 0x78 */
    S17 s2;          /* 0x89 */
} Info;
typedef struct Req {
    int id;
    B48 blk;
    int f34;
    P64 pairs;
    S17 s1;
    S17 s2;
    int f9C;
} Req;
extern Info D_005842DC;
extern short D_0058438E;
extern short D_00584390;
extern char D_00584378[];
int func_00444FF0(int, int, int, int);
int func_00444EC0(void);
int func_002D0850(void*);
int func_004449C0(int, int, int, int);
int func_002CF420(Req*, int*);
void func_002EBCE0(void*);
void func_002D0560(void*);
int MGCLUpdate(void);
void memset(void*, int, int);

static inline int Inner_4441D0(Req* req, int* out, char* buf138) {
    int ret;
    if (D_005842DC.blk.w[0] != 0) {
        req->id = D_005842DC.id;
        req->blk = D_005842DC.blk;
        req->f34 = D_005842DC.f34;
        req->pairs = D_005842DC.pairs;
        req->s1 = D_005842DC.s1;
        req->s2 = D_005842DC.s2;
        req->f9C = 0;
    } else {
        return -12;
    }
    ret = func_002CF420(req, out);
    if (ret != 0) return ret;
    D_00584390 = 0;
    D_0058438E = 1;
    func_002EBCE0(buf138);
    func_002D0560(D_00584378);
    ret = MGCLUpdate();
    if (ret != 0) return ret;
    return 0;
}

int func_004441D0(int a0, int a1, int a2, int a3) {
    int out;
    char buf138[4];
    char bufF0[0x48];
    Req req;

    if (!(unsigned char)func_00444FF0(1, 4, 1, 0)) return -12;
    if (func_00444EC0() != 0) return -12;
    if (func_002D0850(bufF0) != 0) return -12;
    if (func_004449C0(a0, a1, a2, a3) != 0) return -12;
    memset(&req, 0, sizeof(req));
    memset(&out, 0, 4);
    return Inner_4441D0(&req, &out, buf138) != 0 ? -12 : 0;
}

