/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#pragma exceptions off
#include "types.h"

struct VObj {
    virtual void v00(); virtual void v01();
    virtual void Method10(); /* +0x10 */
};

struct Owner { char pad[0x30]; VObj* child; };

/* Forwards to virtual method +0x10 of the object held at +0x30. */
extern "C" void func_003EA590(Owner* o)
{
    o->child->Method10();
}
