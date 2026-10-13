#include "types.h"
typedef struct { float f[12]; } V4_CE60;
typedef struct { int w[16]; } Blk_CE60;
typedef struct { char c[0x11]; } Str11_CE60;
typedef struct {
    char p0[0xE8]; int fE8; int fEC; int fF0; int fF4; unsigned char fF8; unsigned char fF9;
} Room_CE60;
typedef struct {
    char p0[0x180]; int f180; int f184; char p188[0x24C - 0x188]; int f24C;
    char p250[0x278 - 0x250]; int f278; V4_CE60 v; int f2AC; Blk_CE60 blk;
    Str11_CE60 s2F0; Str11_CE60 s301; char p312[0xAA4 - 0x312]; char fAA4[0x2C];
    Room_CE60 room; char pBCC[0x2410 - 0xAD0 - sizeof(Room_CE60)]; int f2410; char p2414[4];
    char name[0x11]; char f2429[0x2480 - 0x2429]; int f2480; int f2484;
} S44CE60;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern int func_00443020(char*);
extern void func_00451B00(S44CE60*, int, char*, int);
extern void func_00452F70(S44CE60*, int, int);
extern int func_004534A0(S44CE60*, int, int, int);
extern int func_004689F8(void*, void*);
extern int func_00468F78(void*);
extern int func_00451200(S44CE60*, int);
extern void func_00449A00(S44CE60*);
extern void func_00452F30(S44CE60*, int, Room_CE60*);
extern void func_004505E0(S44CE60*, Room_CE60*);
extern void func_00450880(S44CE60*, int, char*, int, Room_CE60*);
extern void func_00449800(S44CE60*, int);
extern void* memset(void*, int, int);
extern int D_00497728;
extern int D_00497740;
extern int D_00497890;
extern Room_CE60 D_00585E90;
extern char D_004C0E80[];
extern char func_00447220[];
extern char func_00447D80[];
extern char func_00447D70[];

static inline unsigned char Login_CE60(S44CE60* s)
{
    struct { char f0[0x14]; int f14; } req;
    memset(&req, 0, sizeof(req));
    String_Copy(req.f0, s->name);
    req.f14 = 1;
    s->f24C = func_00468F78(&req);
    if (s->f24C != 0) {
        func_00451B00(s, 0xD, D_004C0E80, 0x2D1);
        return 0;
    }
    return 1;
}

int func_0044CE60(S44CE60* s)
{
    struct {
        int f0; V4_CE60 v; int f34; Blk_CE60 blk; Str11_CE60 s78; Str11_CE60 s89;
        char p9A[0xF0 - 0x9A]; int fF0; void* fF4; void* fF8; void* fFC;
    } req;
    char buf[8];
    int n;
    Room_CE60* room;

    func_00452F70(s, 2, 3);
    n = 0;
    memset(&req, 0, sizeof(req));
    memset(buf, 0, sizeof(buf));
    req.f0 = s->f278;
    req.v = s->v;
    req.f34 = s->f2AC;
    req.blk = s->blk;
    req.s78 = s->s2F0;
    req.s89 = s->s301;
    req.fF0 = D_00497728;
    req.fF4 = func_00447220;
    req.fF8 = func_00447D80;
    req.fFC = func_00447D70;
    while (n < D_00497740 && s->f180 == -1) {
        func_00452F70(s, 0, 0);
        n++;
        s->f24C = func_004689F8(&req, buf);
        if (s->f24C == 0) {
            s->f184 = 0;
            s->f2410 = func_00443E70();
            while (s->f184 == 0) {
                func_00452F70(s, 0, 0);
                if (func_004534A0(s, s->f2410, D_00497890, 0) == 0) {
                    func_00451B00(s, 2, D_004C0E80, 0x184);
                    break;
                }
            }
        }
    }
    if (s->f180 == -1) {
        func_00451B00(s, 0xC, D_004C0E80, 0x18D);
        return 0;
    }
    if (!Login_CE60(s)) {
        return 0;
    }
    {
        unsigned char ok = func_00451200(s, s->f2480);
        func_00449A00(s);
        room = ok ? &s->room : &D_00585E90;
    }
    func_00452F30(s, 0, room);
    room->fE8 = s->f2484;
    room->fF4 = func_00443020(s->f2429);
    room->fEC = 0;
    room->fF9 = 0;
    room->fF0 = 0;
    room->fF8 = 5;
    func_004505E0(s, room);
    func_00450880(s, s->f2480, s->fAA4, room->fF4, room);
    func_00449800(s, 1);
    return 1;
}

