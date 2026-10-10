/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct LightBase { int unk0; }; /* data before the vtable pointer (vptr at +4) */
struct Light : LightBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void Method30(); /* +0x30 */
};

typedef struct cGameLight {
    char pad[0x2C];
    unsigned char enabled; /* +0x2C */
    unsigned char active;  /* +0x2D */
    unsigned char hidden;  /* +0x2E */
    char pad2F[0x60 - 0x2F];
    Light* light;          /* +0x60 */
    unsigned char pending; /* +0x64 */
} cGameLight;

/* If the pending flag (+0x64) is set: clears it and, when active && enabled && !hidden, calls the light (+0x60) virtual +0x30. */
extern "C" void func_00179A90(cGameLight* self)
{
    if (self->pending) {
        bool on;
        self->pending = 0;
        on = self->active && self->enabled && !self->hidden;
        if (on)
            self->light->Method30();
    }
}
