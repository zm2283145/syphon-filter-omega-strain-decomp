/*
 * SFOGame/Source/SpecFxDefs: 1 file, 00230610
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00230610 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

extern void* cGOBJ_SOBJ_convert(void*);
extern void Global_SpawnLight(void*, int, float, float);

/* Script: SpawnLight(owner, a, b); arguments are staged through the stack. */
int Script_SpawnLight(ScriptArg* args) {
    int b[1];
    int a[1];
    float bValue;
    void* owner;
    b[0] = args[2].i;
    a[0] = args[1].i;
    bValue = *(float*)b;
    owner = cGOBJ_SOBJ_convert(args[0].p);
    Global_SpawnLight(owner, 1, *(float*)a, bValue);
    return 0;
}
static inline void merge_flush_func_00230610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00230610 */
