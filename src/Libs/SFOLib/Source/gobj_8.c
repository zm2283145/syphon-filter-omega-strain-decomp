/*
 * Libs/SFOLib/Source/gobj: 1 file, 003CD5C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CD5C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vslot_classes.h"

typedef struct Node_3CD5C0 { void* vt; unsigned char pad[0xC]; unsigned char data[0x40]; unsigned char dirty; } Node_3CD5C0;
typedef struct { unsigned char pad0[0x50]; Node_3CD5C0* node; } Obj_3CD5C0;
extern "C" unsigned char g_IdentityMatrix[];
extern "C" void cGOBJ_CreateMovementInfo_cMatrixR(Obj_3CD5C0* o, void* data);

extern "C" void cGOBJ_CreateMovementInfo_void(Obj_3CD5C0* o)
{
    Node_3CD5C0* n = o->node;
    void* d;
    if (n) {
        if (n->dirty)
            ((VSlots67*)n)->slot20();
        d = n->data;
    } else {
        d = g_IdentityMatrix;
    }
    cGOBJ_CreateMovementInfo_cMatrixR(o, d);
}
static inline void merge_flush_func_003CD5C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD5C0 */
