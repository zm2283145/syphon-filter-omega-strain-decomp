#include "types.h"
typedef struct { char p0[0x1A4]; int done; char p1A8[0xA4]; int f24C; char p250[0x100]; char f350[0x18]; int f368; char p36C[0x20A4]; int t0; } S44CBE0;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451B00(S44CBE0*, int, char*, int);
extern void func_00452F70(S44CBE0*, int, int);
extern int func_004534A0(S44CBE0*, int, int, int);
extern int func_00469000(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0E78[];
extern char D_004C0E80[];
extern char func_004471B0[];
#pragma push
#pragma opt_common_subs off
int func_0044CBE0(S44CBE0* s)
{
    struct { char a[0x18]; int flag; } req;

    memset(&req, 0, sizeof(req));
    memset(s->f350, 0, 0x30);
    String_Copy(req.a, D_004C0E78);
    req.flag = 1;
    s->f24C = func_00469000(&req, func_004471B0);
    if (s->f24C != 0) {
        func_00451B00(s, 0x11, D_004C0E80, 0x222);
        return 0;
    }
    s->done = 0;
    s->t0 = func_00443E70();
    while (s->done == 0) {
        func_00452F70(s, 0, 0);
        if (func_004534A0(s, s->t0, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0E80, 0x22E);
            return 0;
        }
    }
    if (s->f368 != 0) {
        func_00451B00(s, 0x11, D_004C0E80, 0x236);
        return 0;
    }
    return 1;
}
#pragma pop
