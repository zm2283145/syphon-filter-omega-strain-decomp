#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Obj3BA9A0 { VPAD16(a) VPAD1(b) virtual void Clear(int f); virtual void s18(); virtual void Remove(void* e, int f);
    char pad[0xA0]; char mA4[0xC]; };
extern "C" {
extern char D_004DF640[];
int func_003BAA80(void* l);
void** func_003BAA90(void* l);
void func_0036FB30(void* p, int f);
void func_0036FC80(void* p, int f);
void operator_delete(void* p);
}
static inline bool Empty3BA9A0(void* l) { return func_003BAA80(l); }
static inline void Base3BA9A0(Obj3BA9A0* self)
{
    if (self) {
        *(void**)self = D_004DF640;
        self->Clear(1);
        while (!Empty3BA9A0(self->mA4)) self->Remove(*func_003BAA90(self->mA4), 1);
        func_0036FB30(self->mA4, -1);
        func_0036FC80(self, 0);
    }
}
extern "C" Obj3BA9A0* func_003BA9A0(Obj3BA9A0* self, short del)
{
    if (self) {
        Base3BA9A0(self);
        if (del > 0) operator_delete(self);
    }
    return self;
}
