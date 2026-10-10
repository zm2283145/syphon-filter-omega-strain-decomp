/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of FxNode: only the slots used here are named (vtable offset in comments). */
struct FxNode {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Method58(); /* +0x58 */
    char pad04[0x40 - 4];
    char sub40[0x10];     /* +0x40 */
    unsigned char flag50; /* +0x50 */
};

/* Calls the virtual at vtable+0x58 when the flag at +0x50 is set; returns the sub-object at +0x40. */
extern "C" void* func_001E20C0(FxNode* self)
{
    if (self->flag50)
        self->Method58();
    return self->sub40;
}
