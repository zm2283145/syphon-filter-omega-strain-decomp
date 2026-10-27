/*
 * SFOGame/Source/playerControls: 1 file, 002504C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002504C0 */
#pragma push /* merge_units */
#include "types.h"
unsigned int D_004A7540[2] = { 0x0, 0x0 };
typedef struct { char pad[0x60]; float unk60; } Obj002504C0;
/* Store half of a global float into field 0x60 of the second argument. */
void cPlayerControls_InitializeCamera(int unused, Obj002504C0* obj)
{
    obj->unk60 = 0.5f * (*(float*)D_004A7540);
}
static inline void merge_flush_func_002504C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002504C0 */
