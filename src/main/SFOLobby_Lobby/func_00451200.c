#include "types.h"
typedef struct {
    char p0[0x1C8]; int f1C8; char p1CC[0x24C - 0x1CC]; int f24C;
    char p250[0xAA4 - 0x250]; char fAA4[0x2C]; char fAD0[0xF4]; int fBC4;
    char pBC8[0x2418 - 0xBC8]; char name[0x11];
} S451200;
extern int D_00497890;
extern char D_004C0F68[];
extern char D_004C0F70[];
extern char func_00446DB0[];
extern int func_00443E70(void);
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int func_0046A048(void*, void*);
extern void func_00451B00(S451200*, int, char*, int);
extern void func_00452F70(S451200*, int, int);
extern int func_004534A0(S451200*, int, int, int);
extern void func_00450880(S451200*, int, char*, int, int);
extern void* memset(void*, int, int);

int func_00451200(S451200* s, int id)
{
    struct { char f0[0x15]; char f15[0x13]; int f28; } req;
    int t;

    if (id < 0) {
        func_00451B00(s, 0x1D, D_004C0F70, 0x14C);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.f0, D_004C0F68);
    strncpy(req.f15, s->name, 0x11);
    req.f28 = id;
    s->f24C = func_0046A048(&req, func_00446DB0);
    if (s->f24C != 0) {
        func_00451B00(s, 1, D_004C0F70, 0x15A);
        return 0;
    }
    t = func_00443E70();
    s->f1C8 = 0;
    while (s->f1C8 == 0) {
        func_00452F70(s, 0, 0);
        if (func_004534A0(s, t, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0F70, 0x168);
            return 0;
        }
    }
    func_00450880(s, id, s->fAA4, s->fBC4, (int)s->fAD0);
    return 1;
}

