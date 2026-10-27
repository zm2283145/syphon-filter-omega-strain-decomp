/*
 * main/npc: range (2 files, 0014D350-0014D390)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "npc_types.h"

/* merge_units: begin func_0014D350 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; } Tracked;
typedef struct { Tracked* obj; int serial; } WeakRef;

/* Returns the referenced object if it is still the same instance (serial matches), else 0. */
Tracked* cSafePtr_cGOBJ_GetPtr_void(WeakRef* self)
{
    Tracked* obj = self->obj;
    unsigned char valid = 1;
    if ((!obj) == 0 && obj->serial != self->serial)
        valid = 0;
    return valid ? obj : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D350 */

/* merge_units: begin func_0014D390 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */


/* vtable slot 0x28. */
int cNPC_UseCurrentLookAt(cNPC* self, unsigned char i) {
    return self->unk17C[i].unk00;
}

/* vtable slot 0x27. */
signed char cNPC_v27(cNPC* self) {
    return self->unk13C;
}

/* vtable slot 0x34. */
float cNPC_GetRawTravelSpeed(cNPC* self) {
    return self->unk060;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D390 */
