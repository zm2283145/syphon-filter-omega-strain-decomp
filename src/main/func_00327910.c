#pragma cplusplus on
#include "vslot_pad.h"
class C27910 {
public:
    VPAD8(p) VPAD2(q)
    virtual void Slot10();
};
struct H27910 { char pad[0x44]; C27910* obj; };
struct T27910 { char pad[0x5C]; H27910* h; };
extern "C" char D_005381F0[];
extern "C" void func_0037A1E0(char* p);
extern "C" void func_0041E470(T27910* self);
extern "C" void func_00327910(T27910* self)
{
    if (self->h) {
        self->h->obj->Slot10();
        func_0037A1E0(D_005381F0);
    }
    func_0041E470(self);
}