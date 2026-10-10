/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19();
    virtual void Method70(int a, int b); /* +0x70 */
    char pad04[0x50 - 4];
    int unk50; /* +0x50 */
    int unk54; /* +0x54 */
};

extern "C" void func_0041E2B0(Widget* self);

/* func_0041E2B0 then virtual slot +0x70 with fields +0x50/+0x54. */
extern "C" void func_004249D0(Widget* self)
{
    func_0041E2B0(self);
    self->Method70(self->unk50, self->unk54);
}
