/*
 * main/GuiAgentInfo: range (2 files, 00362CE0-00362CF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00362CE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


int func_00362CE0(char* self) {
    return *(int*)(self + 176);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00362CE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00362CE0 */

/* merge_units: begin func_00362CF0 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct { char pad[0x40]; Q v; } Obj40;

/* Copies a quadword into the object's field at +0x40. */
void func_00362CF0(Obj40* obj, Q* v)
{
    obj->v = *v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00362CF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00362CF0 */
