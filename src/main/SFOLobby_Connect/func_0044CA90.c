#include "types.h"
typedef struct { char p0[0x1A4]; int f1A4; int done; char p1AC[0xA0]; int f24C; char p250[0x130]; char f380[0x18]; int f398; char p39C[0x2074]; int t0; char p2414[4]; char name[0x20]; } S44CA90;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451B00(S44CA90*, int, char*, int);
extern void func_00452F70(S44CA90*, int, int);
extern int func_004534A0(S44CA90*, int, int, int);
extern int func_004690A0(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0E78[];
extern char D_004C0E80[];
extern char func_00447470[];
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
int func_0044CA90(S44CA90* s)
{
    struct { char a[0x15]; char b[0x11]; } req;
    memset(&req, 0, sizeof(req));
    memset(s->f380, 0, 0x1C);
    String_Copy(req.a, D_004C0E78);
    String_Copy(req.b, s->name);
    s->f24C = func_004690A0(&req, func_00447470);
    if (s->f24C != 0) {
        func_00451B00(s, 0x12, D_004C0E80, 0x25F);
        return 0;
    }
    s->done = 0;
    s->f1A4 = 0;
    s->t0 = func_00443E70();
    while (s->done == 0) {
        func_00452F70(s, 0, 0);
        if (func_004534A0(s, s->t0, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0E80, 0x26C);
            return 0;
        }
    }
    if (s->f398 < 0) {
        func_00451B00(s, 0x12, D_004C0E80, 0x274);
        return 0;
    }
    return 1;
}
#pragma pop
