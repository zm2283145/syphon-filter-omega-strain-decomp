#include "types.h"
typedef struct { char p0[0x20C]; int done; char p210[0x3C]; int f24C; char p250[0x1AB8]; char res[0x18]; int err; char p1D24[0x6E4]; signed char busy; char p2409[0xF]; char name[0x20]; } S44E060;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451B00(S44E060*, int, char*, int);
extern void func_00452F70(S44E060*, int, int);
extern int func_004534A0(S44E060*, int, int, int);
extern void func_0046A0E8(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0EF0[];
extern char D_004C0F00[];
extern char func_00446B40[];
static inline int NonZero44E060(int v) { return v != 0; }
#pragma push
#pragma opt_common_subs off
#pragma bool off
char* func_0044E060(S44E060* s, int arg)
{
    struct { char a[0x15]; char b[0x13]; int arg; } req;
    int t0;

    s->done = 0;
    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0EF0);
    String_Copy(req.b, s->name);
    req.arg = arg;
    func_0046A0E8(&req, func_00446B40);
    t0 = func_00443E70();
    s->busy = 1;
    while (NonZero44E060(s->done) ^ 1) {
        func_00452F70(s, 0, 0);
        if (s->f24C != 0) {
            s->busy = 0;
            return 0;
        }
        if (func_004534A0(s, t0, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0F00, 0x2FE);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    return s->err == 0 ? s->res : 0;
}
#pragma pop
