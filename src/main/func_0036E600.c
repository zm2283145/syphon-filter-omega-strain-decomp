#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Obj36E600 { VPAD16(a) VPAD1(b) virtual void Clear(int f); virtual void s18(); virtual void Remove(void* e, int f);
    char pad[0xA0]; char mA4[4]; int count; void** items; };
extern "C" {
extern char D_004DF640[];
extern char D_004DF6A0[];
void func_0036E6E0(void* p, int f);
void operator_delete(void* p);
}
static inline void Base36E600(Obj36E600* p) { if (p) *(void**)p = D_004DF6A0; }
extern "C" Obj36E600* func_0036E600(Obj36E600* self, short del)
{
    if (self) {
        *(void**)self = D_004DF640;
        self->Clear(1);
        while (self->count) self->Remove(self->items[*(volatile int*)&self->count - 1], 1);
        if (self->mA4) func_0036E6E0(self->mA4, -1);
        Base36E600(self);
        if (del > 0) operator_delete(self);
    }
    return self;
}
