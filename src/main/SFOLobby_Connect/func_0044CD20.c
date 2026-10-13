#include "types.h"
typedef struct {
    char p0[0x19C]; int f19C; int f1A0; char p1A4[0x24C - 0x1A4]; int f24C;
    char p250[0x17CC - 0x250]; char f17CC[0x11C]; signed char f18E8; char p18E9[3];
    char f18EC[0x22C]; signed char f1B18; char p1B19[0x2410 - 0x1B19]; int f2410;
    char p2414[0x26A4 - 0x2414]; int f26A4;
} S44CD20;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451B00(S44CD20*, int, char*, int);
extern void func_00452F70(S44CD20*, int, int);
extern int func_004534A0(S44CD20*, int, int, int);
extern int func_0046BFF0(void*, void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0E78[];
extern char D_004C0E80[];
extern char func_00447130[];
extern char func_00447070[];
int func_0044CD20(S44CD20* s)
{
    struct { char f0[0x18]; int f18; int f1C; int f20; } req;

    memset(&req, 0, sizeof(req));
    memset(s->f17CC, 0, 0x120);
    memset(s->f18EC, 0, 0x230);
    String_Copy(req.f0, D_004C0E78);
    req.f18 = 3;
    req.f1C = 2;
    req.f20 = s->f26A4;
    s->f24C = func_0046BFF0(&req, func_00447130, func_00447070);
    if (s->f24C != 0) {
        return 0;
    }
    s->f19C = 0;
    s->f1A0 = 0;
    s->f2410 = func_00443E70();
    do {
        func_00452F70(s, 0, 0);
        if (func_004534A0(s, s->f2410, D_00497890, 1) == 0) {
            func_00451B00(s, 2, D_004C0E80, 0x1E6);
            return 0;
        }
    } while (!s->f19C || !s->f1A0 || s->f18E8 != 1 || s->f1B18 != 1);
    return 1;
}
