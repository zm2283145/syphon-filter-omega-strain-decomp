#include "types.h"
typedef struct { void* vt; char pad[0x5C]; char m60[0x10]; char m70[0x10]; char m80[0x20]; char mA0[0x10]; char mB0[0x10]; char mC0[0x10]; char mD0[4]; } O32ACD0;
extern char D_004DE790[];
extern void func_0013A040(void* p, int f);
extern void func_0032ADE0(void* p, int f);
extern void func_0041F370(void* p, int f);
extern void operator_delete(void* p);
O32ACD0* func_0032ACD0(O32ACD0* self, short del)
{
    if (self) {
        self->vt = D_004DE790;
        if (self->mD0)
            func_0013A040(self->mD0, -1);
        if (self->mC0)
            func_0013A040(self->mC0, -1);
        if (self->mB0)
            func_0013A040(self->mB0, -1);
        if (self->mA0)
            func_0013A040(self->mA0, -1);
        if (self->m80)
            func_0013A040(self->m80, -1);
        if (self->m70)
            func_0013A040(self->m70, -1);
        if (self->m60)
            func_0032ADE0(self->m60, -1);
        func_0041F370(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}