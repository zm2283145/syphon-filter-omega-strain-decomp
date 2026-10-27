/*
 * main/gameCamera: range (2 files, 0017F8B0-0017F960)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0017F8B0 */
#pragma push /* merge_units */
#pragma peephole off
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { unsigned char on; char pad[0xF]; V4 a; V4 b; } Obj;
extern signed char D_004E1D88;
extern V4 D_004E1D90;
/* Inlined cVector_GetZero (cVector_GetZero): lazily zeroed shared vector. */
static inline V4* Vec4_Zero(void) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return &D_004E1D90;
}
/* Sets the flag and clears both vectors. */
Obj* func_0017F8B0(Obj* o) {
    o->on = 1;
    o->a = *Vec4_Zero();
    o->b = *Vec4_Zero();
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F8B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017F8B0 */

/* merge_units: begin func_0017F960 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_0017F960;
V4_0017F960 cVector_Get0001(void) {
    V4_0017F960 l0;
    V4_0017F960* q1 = &l0;
    asm {
        sqc2 vf0, 0x0(q1)
    }
    return l0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017F960 */
