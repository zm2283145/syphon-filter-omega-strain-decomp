#include "types.h"
typedef struct { char p0[0x70]; char f70[0x184]; int done; char p1F8[0x54]; int f24C; char p250[0x21B8]; signed char busy; char p2409[7]; int t0; char p2414[4]; char name[0x20]; } S449510;
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int func_00443E70(void);
extern void func_0044F7E0(void*);
extern void func_00451B00(S449510*, int, char*, int);
extern void func_00452F70(S449510*, int, int);
extern int func_004534A0(S449510*, int, int, int);
extern int func_00466FF0(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_00448270[];
static inline int NonZero449510(int v) { return v != 0; }
#pragma push
#pragma opt_common_subs off
#pragma bool off
#pragma opt_rotateloops off
int func_00449510(S449510* s)
{
    struct { char a[0x15]; char b[0x13]; int x; int y; } req;
    func_0044F7E0(s->f70);
    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    strncpy(req.b, s->name, 0x11);
    req.x = 1;
    req.y = 0x100;
    s->done = 0;
    s->t0 = func_00443E70();
    s->f24C = func_00466FF0(&req, func_00448270);
    if (s->f24C != 0) {
        func_00451B00(s, 1, D_004C0D10, 0x5AC);
        return 0;
    }
    while (NonZero449510(s->done) ^ 1) {
        func_00452F70(s, 0, 0);
        if (s->f24C != 0) {
            func_00451B00(s, 1, D_004C0D10, 0x5B8);
            s->busy = 0;
            return 0;
        }
        if (func_004534A0(s, s->t0, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0D10, 0x5C0);
            s->busy = 0;
            return 0;
        }
    }
    return 1;
}
#pragma pop
