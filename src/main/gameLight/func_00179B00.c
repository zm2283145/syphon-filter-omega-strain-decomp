/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct LightBase { int unk0; }; /* data before the vtable pointer (vptr at +4) */

/* Virtual-call view of Light: only the slots used here are named (vtable offset in comments). */
struct Light : LightBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08();
    virtual void Method2C(); /* +0x2C */
};

typedef struct SceneLight {
    char pad[0x2C];
    unsigned char enabled;   /* +0x2C */
    unsigned char active;    /* +0x2D */
    unsigned char paused;    /* +0x2E */
    char pad2F[0x60 - 0x2F];
    Light* light;            /* +0x60 */
    unsigned char triggered; /* +0x64 */
} SceneLight;

static inline bool IsLive(SceneLight* o)
{
    return o->active && o->enabled && !o->paused;
}

/* One-shot: marks the light triggered and, while the object is live, calls the light's virtual +0x2C. */
extern "C" void func_00179B00(SceneLight* self)
{
    if (self->triggered)
        return;
    self->triggered = 1;
    if (IsLive(self))
        self->light->Method2C();
}
