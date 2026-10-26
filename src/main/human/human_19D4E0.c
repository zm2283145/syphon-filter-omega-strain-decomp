/*
 * main/human: range (2 files, 0019D4E0-0019D500)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0019D4E0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cQuaternion_InvertUnitQuat(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D4E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D4E0 */

/* merge_units: begin func_0019D500 */
#pragma push /* merge_units */
extern int Root_GetParent(void* self);
extern void Root_RefreshWorldCache(void* self);
extern char* Root_Identity(void* self);
void* Root_GetWorldQuat(void* self) {
    if (Root_GetParent(self)) {
        Root_RefreshWorldCache(self);
        return Root_Identity(self);
    }
    return Root_Identity(self) + 0x50;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D500 */
