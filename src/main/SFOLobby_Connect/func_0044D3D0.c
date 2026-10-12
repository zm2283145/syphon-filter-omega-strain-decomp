#include "types.h"
typedef struct { char p0[0x188]; int done; char p18C[0xC0]; int f24C; char p250[0xFC]; int f34C; char p350[0x20C0]; int t0; char p2414[4]; char name[0x28C]; int f26A4; } S44D3D0;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451B00(S44D3D0*, int, char*, int);
extern void func_00452F70(S44D3D0*, int, int);
extern int func_004534A0(S44D3D0*, int, int, int);
extern int func_0046BEB0(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0E78[];
extern char D_004C0E80[];
extern char func_00445F40[];
#pragma push
#pragma opt_common_subs off
int func_0044D3D0(S44D3D0* s)
{
    struct { char a[0x15]; char b[0x13]; int x; int z; } req;

    memset(&req, 0, sizeof(req));
    req.x = 2;
    req.z = s->f26A4;
    String_Copy(req.a, D_004C0E78);
    String_Copy(req.b, s->name);
    s->f24C = func_0046BEB0(&req, func_00445F40);
    if (s->f24C != 0) {
        func_00451B00(s, 1, D_004C0E80, 0x68);
        return 0;
    }
    s->done = 0;
    s->t0 = func_00443E70();
    while (s->done == 0) {
        func_00452F70(s, 0, 0);
        if (func_004534A0(s, s->t0, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0E80, 0x75);
            return 0;
        }
    }
    if (s->f34C != 0) {
        func_00451B00(s, 1, D_004C0E80, 0x7E);
        return 0;
    }
    return 1;
}
#pragma pop
