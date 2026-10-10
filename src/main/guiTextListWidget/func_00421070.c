/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Widget: only the slots used here are named (vtable offset in comments). */
struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int flag, int value); /* +0x5C */
    char pad04[0x90 - 4];
    int sub90; /* +0x90 */
    int unk94; /* +0x94 */
};

extern "C" void func_00421F90(int* sub);
extern "C" void func_00424430(Widget* self, int a, int b);

/* Resets the +0x90 sub-object, calls virtual +0x5C(1, +0x94), then func_00424430(self, 0, 0). */
extern "C" void func_00421070(Widget* self)
{
    func_00421F90(&self->sub90);
    self->Method5C(1, self->unk94);
    func_00424430(self, 0, 0);
}
