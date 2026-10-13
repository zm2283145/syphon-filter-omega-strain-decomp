#include "types.h"
typedef struct { int a; int count; char p8[0x18 - 0x8]; unsigned char flag; } Sub_4516E0;
typedef struct {
    char p0[0x8C];
    Sub_4516E0 s8C;
    char pA8[0x24C - 0xA8];
    int f24C;
    char p250[0x1E98 - 0x250];
    int t98;
    char p1E9C[0x1EA0 - 0x1E9C];
    int mode;
    char p1EA4[0x1EAC - 0x1EA4];
    int fAC;
    char p1EB0[0x2409 - 0x1EB0];
    unsigned char f2409;
    char p240A[0x255C - 0x240A];
    int state;
} Main_4516E0;
typedef struct { char proto[0x18]; int id; } Req_4516E0;
extern void* memset(void*, int, unsigned int);
extern void String_Copy(char*, const char*);
extern int func_0046C290(Req_4516E0* a, void* b);
extern int func_00443E70(void);
extern void func_00447A30(void);
extern void func_0044F7E0(Sub_4516E0*);
extern void func_0044F160(Sub_4516E0*, int);
extern void func_0044F280(Sub_4516E0*, int);
extern void func_00450B30(Main_4516E0*);
extern void func_00453FA0(Main_4516E0*, void*);
extern void func_004498C0(Main_4516E0*);
extern void func_0044D700(Main_4516E0*, int);
extern void func_00449800(Main_4516E0*, int);
extern void func_00451B30(Main_4516E0*);
extern int D_00497788;
extern char D_004C0F68[];
static inline void Tick_4516E0(Main_4516E0* self) {
    if (func_00443E70() - self->t98 > D_00497788) {
        Req_4516E0 r;
        memset(&r, 0, sizeof(r));
        String_Copy(r.proto, D_004C0F68);
        r.id = self->fAC;
        self->f24C = func_0046C290(&r, func_00447A30);
        if (self->f24C != 0)
            return;
        self->t98 = func_00443E70();
        func_0044F7E0(&self->s8C);
        func_0044F160(&self->s8C, 1);
    }
    if (self->s8C.flag && self->s8C.count > 0)
        func_0044F280(&self->s8C, 0);
}
void func_004516E0(Main_4516E0* self) {
    if (self->state == 5 && !self->f2409) {
    switch (self->mode) {
    case 0:
        Tick_4516E0(self);
        func_00450B30(self);
        func_00453FA0(self, &self->s8C);
        break;
    case 1:
        Tick_4516E0(self);
        func_00450B30(self);
        func_00453FA0(self, (char*)self + 0xA8);
        break;
    }
    func_004498C0(self);
    func_0044D700(self, 0);
    func_00449800(self, 0);
    func_00451B30(self);
    }
}

