/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct LightBase { int unk0; }; /* data before the vtable pointer (vptr at +4) */
struct Light : LightBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08();
    virtual void Method2C(); /* +0x2C */
};

typedef struct cGameLight { char pad[0x60]; Light* light; /* +0x60 */ } cGameLight;

extern "C" void Object_Activate(cGameLight* self, void* arg);

/* Object_Activate then light object (+0x60) virtual slot +0x2C. */
extern "C" void func_00179BB0(cGameLight* self, void* arg)
{
    Object_Activate(self, arg);
    self->light->Method2C();
}
