/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(); /* +0x5C */
    char pad04[0x48 - 4];
    void* list; /* +0x48 */
    char pad4C[0x60 - 0x4C];
    int index; /* +0x60 */
};

extern "C" void func_0041EFA0(Widget* self);
extern "C" void func_00421070(void* list);
extern "C" void func_00424430(void* list, int a, unsigned int index);

/* func_0041EFA0(self); if +0x48 is set: func_00421070, virtual +0x5C, then func_00424430(+0x48, 0, +0x60). */
extern "C" void func_00356C70(Widget* self)
{
    func_0041EFA0(self);
    if (self->list) {
    func_00421070(self->list);
    self->Method5C();
    func_00424430(self->list, 0, self->index);
    }
}
