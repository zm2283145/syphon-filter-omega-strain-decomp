#include "types.h"
typedef struct { char p0[0x224]; int done; char p228[0x24]; int f24C; char p250[0x21B8]; signed char busy; char p2409[7]; int t0; char p2414[4]; char name[0x20]; } S449660;
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int func_00443E70(void);
extern void func_00451B00(S449660*, int, char*, int);
extern void func_00452F70(S449660*, int, int);
extern int func_004534A0(S449660*, int, int, int);
extern int func_00467138(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_00447D90[];
static inline int NonZero449660(int v) { return v != 0; }
#pragma push
#pragma opt_common_subs off
#pragma bool off
void func_00449660(S449660* s, int arg)
{
    struct { char a[0x15]; char b[0x13]; int arg; } req;

    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    strncpy(req.b, s->name, 0x11);
    req.arg = arg;
    s->done = 0;
    s->f24C = func_00467138(&req, func_00447D90);
    if (s->f24C == 0) {
        s->t0 = func_00443E70();
        while (NonZero449660(s->done) ^ 1) {
            func_00452F70(s, 0, 0);
            if (func_004534A0(s, s->t0, D_00497890, 0) == 0) {
                func_00451B00(s, 2, D_004C0D10, 0x584);
                s->busy = 0;
                break;
            }
        }
    }
}
#pragma pop
