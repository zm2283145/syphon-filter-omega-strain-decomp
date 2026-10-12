#include "types.h"
typedef struct { char p0[0x1DC]; int done; char p1E0[0x6C]; int f24C; char p250[0x21B8]; signed char busy; char p2409[0xF]; char name[0x68]; int f2480; char p2484[0x104]; int f2588; int last; } S449360;
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int func_00443E70(void);
extern void func_0044A810(S449360*, int);
extern void func_00451B00(S449360*, int, char*, int);
extern void func_00452F70(S449360*, int, int);
extern int func_004534A0(S449360*, int, int, int);
extern int func_00467090(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_004481E0[];
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
int func_00449360(S449360* s, int a, int b, char* msg)
{
    struct { char a[0x15]; char b[0x13]; int x; int y; char msg[0xC8]; } req;
    int h;

    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    strncpy(req.b, s->name, 0x11);
    req.x = a;
    req.y = b;
    strncpy(req.msg, msg, 0xC8);
    if (b == 1) func_0044A810(s, s->f2480);
    s->f24C = func_00467090(&req, func_004481E0);
    if (s->f24C != 0) {
        func_00451B00(s, 1, D_004C0D10, 0x5ED);
        return 0;
    }
    h = func_00443E70();
    s->done = 0;
    s->busy = 1;
    while (s->done == 0) {
        func_00452F70(s, 0, 0);
        if (s->f24C != 0) {
            func_00451B00(s, 1, D_004C0D10, 0x5FB);
            s->busy = 0;
            return 0;
        }
        if (func_004534A0(s, h, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0D10, 0x603);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    s->f2588 = 0;
    s->last = 0;
    return 1;
}
#pragma pop
