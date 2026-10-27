/*
 * SFOGame/Source/VisionFxMan: 1 file, 0025E4A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025E4A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
union A25E4A0 { int i; float f; void* p; };
struct Fx25E4A0 { char p[8]; unsigned char b8; char p9[3]; unsigned char bC, bD; char pE[2]; int f10; float f14, f18, f1C, f20; char p24[4]; float f28; };
extern "C" Fx25E4A0* g_VisionFxMan;
#pragma push
#pragma opt_dead_assignments off
extern "C" int Script_setFxFlair(A25E4A0* args)
{
    Fx25E4A0* f = g_VisionFxMan;
    int tz;
int ty;
int tx;
    float z;
float y;
float x;
    float zero = 0.0f;
    tz = args[3].i; z = *(float*)&tz;
    ty = args[2].i; y = *(float*)&ty;
    tx = args[1].i; x = *(float*)&tx;
    f->b8 = args[0].i;
    f->f10 = 0;
    *(int*)&f->f20 = 0;
    *(int*)&f->f1C = 0;
    *(int*)&f->f18 = 0;
    *(int*)&f->f14 = 0;
    f->bC = 0;
    f->bD = 0;
    *(int*)&f->f14 = 0;
    f->f18 = x;
    f->f1C = y;
    f->f20 = z;
    if (!f->b8) f->f28 = zero;
    return 0;
}
#pragma pop
static inline void merge_flush_func_0025E4A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025E4A0 */
