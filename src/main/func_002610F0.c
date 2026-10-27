#pragma cplusplus on
#include "vslot_classes.h"
struct Obj2610 { void* vt; char pad[0x60]; unsigned char active; };
extern "C" void cIE_GOBJ_Render(Obj2610* self) {
    if (self->active) ((VSlots67*)self)->slot66();
}