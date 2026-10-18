/*
 * main/gameCamera: range (2 files, 0017D510-0017D540)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0017D510 */
#pragma push /* merge_units */
typedef struct { char pad[0xB4]; float fB4; } A1_S;
int func_0017D510(A1_S* o) {
    return !(o->fB4 == 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017D510 */

/* merge_units: begin func_0017D540 */
#pragma push /* merge_units */
typedef struct { int pad0; float v; } F17D540_t;
static inline float F17D540_Max(float a, float b) {
    float r;
    asm {
        mov.s r, a
        max.s r, b, r
    }
    return r;
}
int QuatCurve_Timer(F17D540_t* p, float dt) {
    float old = p->v;
    p->v -= dt;
    p->v = F17D540_Max(p->v, 0.0f);
    return old > 0.0f && p->v == 0.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017D540 */
