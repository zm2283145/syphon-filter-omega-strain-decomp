#include "types.h"
typedef struct { char p0[0x1EA4]; int f1EA4; char p1EA8[0x540]; int img2; int img1; char p23F0[0x16C]; int state; char p2560[0x1C]; int f257C; int f2580; } S44DF80;
extern void func_00451B00(S44DF80*, int, char*, int);
extern void func_00452FC0(S44DF80*);
extern void func_0044F880(int, int, int, int);
extern void func_0044D860(S44DF80*, int);
extern char D_004C0ED0[];
#pragma push
int func_0044DF80(S44DF80* s, int unused, int a, int b)
{
    if (s->state != 9 && s->state != 0) {
        func_00451B00(s, 1, D_004C0ED0, 0x21);
        return 0;
    }
    s->state = 6;
    func_00452FC0(s);
    s->img1 = a;
    s->img2 = b;
    func_0044F880(s->img1, s->f1EA4, 0, 0x68);
    func_0044F880(s->img2, 0x40, 0x20, 0x50);
    s->f257C = 0;
    s->f2580 = 0;
    func_0044D860(s, 0);
    func_00451B00(s, 0, D_004C0ED0, 0x3C);
    return 1;
}
#pragma pop
