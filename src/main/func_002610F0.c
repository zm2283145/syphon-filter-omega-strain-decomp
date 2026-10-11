#pragma cplusplus on
#include "vslot_classes.h"
struct Obj2610 { void* vt; char pad[0x60]; unsigned char active; };
extern "C" void func_002610F0(Obj2610* self) {
    if (self->active) ((VSlots67*)self)->slot66();
}