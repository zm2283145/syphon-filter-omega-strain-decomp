#include "types.h"
typedef struct {
    char p0[0x1C]; char f1C[0x1C]; char f38[0x1C]; char f54[0x1C];
    char p70[0x180 - 0x70]; int f180;
    char p184[0x1EA8 - 0x184]; int f1EA8;
    char p1EAC[0x23DC - 0x1EAC]; void* f23DC;
    char p23E0[0x2404 - 0x23E0]; void* f2404;
    char p2408[0x255C - 0x2408]; int f255C;
    char p2560[4];
    unsigned char err;
} S453B00;
extern void func_00444070(int);
extern void func_0044CA30(S453B00*);
extern void func_004689B0(void);
extern void func_002E9648(void);
extern void func_00444E70(void);
extern void func_0044F6B0(void*);
extern void func_0044BFF0(S453B00*);
extern void func_003A6680(int);
extern void func_004538D0(S453B00*);
extern void func_0044F7E0(void*);

void func_00453B00(S453B00* s, int full)
{
    if (s->f1EA8 > 0) {
        func_00444070(0);
        if (s->f180 > 0)
            func_0044CA30(s);
        if (s->f180 > 0)
            func_0044CA30(s);
        if (full) {
            func_004689B0();
            func_002E9648();
        }
        s->f1EA8 = 0;
        if (full)
            func_00444E70();
        if (s->f2404)
            func_0044F6B0(s->f2404);
        s->f2404 = 0;
        if (s->f23DC)
            func_0044F6B0(s->f23DC);
        s->f23DC = 0;
        s->f1EA8 = full ? 1 : -1;
    }
    if (full) {
        if (s->f1EA8) {
            if (s->f1EA8 == -1) {
                func_004689B0();
                func_00444E70();
                func_002E9648();
            }
            func_0044BFF0(s);
            s->f1EA8 = 0;
        }
        func_003A6680(0);
    }
    s->f180 = -1;
    func_004538D0(s);
    if (full) {
        func_0044F7E0(s->f1C);
        func_0044F7E0(s->f38);
        func_0044F7E0(s->f54);
    }
    s->f255C = 0;
    s->err = 0;
}
