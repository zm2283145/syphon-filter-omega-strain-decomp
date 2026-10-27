#pragma cplusplus on

#include "types.h"
#include "vslot_classes.h"

/* Refresh the attached node (virtual update if flagged) and hand it on. */
typedef struct Node_394520 { void* vt; unsigned char pad[0xC]; unsigned char data[0x40]; unsigned char dirty; } Node_394520;
typedef struct {
    unsigned char pad0[0x38]; int arg;
    unsigned char pad1[0x14]; Node_394520* node;
    unsigned char pad2[0x10]; int target;
} Obj_394520;
extern "C" void cParticle_Render(int target, int arg, void* data);

extern "C" void cPARTICLE_GOBJ_Render(Obj_394520* o)
{
    if (o->target != 0) {
        Node_394520* n = o->node;
        if (n->dirty)
            ((VSlots67*)n)->slot20();
        cParticle_Render(o->target, o->arg, n->data);
    }
}