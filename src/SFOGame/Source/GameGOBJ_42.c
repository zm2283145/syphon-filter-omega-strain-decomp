/*
 * SFOGame/Source/GameGOBJ: 1 file, 0021A170
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021A170 */
#pragma push /* merge_units */
#include "types.h"
#pragma opt_propagation off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* cGOBJ_SOBJ_convert(void*);
extern void Blast_Prepare(void* obj, int kind, float x, float y, float z, int a, int b, int c, int d);
/* Script native: creates a blast of kind args[1] at (args[2], args[3], args[4]) on object args[0]; returns 0. */
int Script_CreateBlast(ScriptArg* args)
{
    int z[1];
    int y[1];
    int x[1];
    volatile int kind;
    float fx, fy, fz;
    z[0] = args[4].i;
    fz = *(float*)z;
    y[0] = args[3].i;
    fy = *(float*)y;
    x[0] = args[2].i;
    fx = *(float*)x;
    kind = args[1].i;
    Blast_Prepare(cGOBJ_SOBJ_convert(args[0].p), kind, fx, fy, fz, 1, 0, 0, 0);
    return 0;
}
#pragma opt_propagation reset
static inline void merge_flush_func_0021A170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A170 */
