/*
 * main/npc: range (2 files, 0014D410-0014D450)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "npc_types.h"

/* merge_units: begin func_0014D410 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; } Tracked;
typedef struct { char pad[0x50]; Tracked* obj; int serial; } RefHolder;

/* Returns the referenced object at +0x50 if it is still the same instance (serial matches), else 0. */
Tracked* func_0014D410(RefHolder* self)
{
    Tracked* obj = self->obj;
    unsigned char valid = 1;
    if ((!obj) == 0 && obj->serial != self->serial)
        valid = 0;
    return valid ? obj : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D410 */

/* merge_units: begin func_0014D450 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */


int func_0014D450(Word* self) {
    return self->value;
}

void* func_0014D460(char* self) {
    return self + 0x2FE0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D450 */
