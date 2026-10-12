#include "types.h"
typedef struct { char p0[0x1EC]; int done; char p1F0[0x103C]; char res[0x18]; int f1244; char p1248[0x11C0]; signed char busy; char p2409[0xF]; char name[0x68]; int f2480; } S449070;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451B00(S449070*, int, char*, int);
extern void func_00452F70(S449070*, int, int);
extern int func_004534A0(S449070*, int, int, int);
extern void func_00466C18(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_00448050[];
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
char* func_00449070(S449070* s, int arg)
{
    struct { char a[0x15]; char b[0x13]; int f58; int arg; } req;
    int h;

    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    String_Copy(req.b, s->name);
    req.arg = arg;
    req.f58 = s->f2480;
    func_00466C18(&req, func_00448050);
    s->f1244 = -0x3C6;
    h = func_00443E70();
    s->done = 0;
    s->busy = 1;
    while (s->done == 0) {
        func_00452F70(s, 0, 0);
        if (func_004534A0(s, h, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0D10, 0x683);
            break;
        }
    }
    s->busy = 0;
    return s->res;
}
#pragma pop
