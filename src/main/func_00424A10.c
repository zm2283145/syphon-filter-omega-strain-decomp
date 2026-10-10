/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Widget: only the slots used here are named (vtable offset in comments). */
struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18();
    virtual void Method6C(int a, int b); /* +0x6C */
    char pad04[0x50 - 4];
    int unk50; /* +0x50 */
    int unk54; /* +0x54 */
};

extern "C" void func_0041E330(Widget* self);

/* Runs func_0041E330, then the virtual at vtable+0x6C with the two words at +0x50/+0x54. */
extern "C" void func_00424A10(Widget* self)
{
    func_0041E330(self);
    self->Method6C(self->unk50, self->unk54);
}
