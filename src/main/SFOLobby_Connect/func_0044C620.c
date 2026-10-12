#include "types.h"
typedef struct { char p0[0x204]; int done; char p208[0x44]; int f24C; char p250[0x21C0]; int t0; char p2414[4]; char name[0x11]; char out[0x14]; } S44C620;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451B00(S44C620*, int, char*, int);
extern void func_00452F70(S44C620*, int, int);
extern int func_004534A0(S44C620*, int, int, int);
extern int func_0046AF60(void*, void*);
extern void* memset(void*, int, int);
extern int strlen(const char*);
extern int D_00497890;
extern char D_004C0E78[];
extern char D_004C0E80[];
extern char func_00446D00[];
#pragma push
#pragma opt_common_subs off
int func_0044C620(S44C620* s)
{
    struct { char a[0x15]; char b[0x11]; } req;

    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0E78);
    String_Copy(req.b, s->name);
    memset(s->out, 0, 0x14);
    s->f24C = func_0046AF60(&req, func_00446D00);
    if (s->f24C != 0) return 0;
    s->done = 0;
    s->t0 = func_00443E70();
    while (s->done == 0) {
        func_00452F70(s, 0, 0);
        if (func_004534A0(s, s->t0, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0E80, 0x38A);
            break;
        }
    }
    if (strlen(s->out) == 0) {
        func_00451B00(s, 1, D_004C0E80, 0x392);
        return 0;
    }
    return 1;
}
#pragma pop
