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
    char pad[0x60];
    Light* light; /* +0x60 */
} SceneLight;

extern "C" void Object_Activate(SceneLight* self, void* arg);

/* Virtual 0x15: runs the base handler, then the light's virtual +0x2C. */
extern "C" void cGameDirectionalLight_v15(SceneLight* self, void* arg)
{
    Object_Activate(self, arg);
    self->light->Method2C();
}
