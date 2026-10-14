/*
 * main/npc: range (2 files, 0014FC00-0014FC20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0014FC00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc.
 */


int func_0014FC00(void) {
    return 0;
}

void func_0014FC10(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC00 */

/* merge_units: begin func_0014FC20 */
#pragma push /* merge_units */
typedef struct { char pad[0x120]; int priority; char pad124[0x13D - 0x124]; char kind; } Obj120;

/* Records a new kind/priority pair unless the current priority is higher. */
void NpcAi_RequestWeaponDraw(Obj120* self, char kind, int priority)
{
    if (priority < self->priority)
        return;
    self->kind = kind;
    self->priority = priority;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC20 */
