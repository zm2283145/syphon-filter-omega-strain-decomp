/*
 * main/game: range (2 files, 001363C0-001364B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop

/* merge_units: begin func_001363C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cGOBJPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001363C0 */

/* merge_units: begin func_001364B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma peephole off
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) V4;
struct R { int a, b, c, d; };
struct T { V4 q; int m10; int m14; };
extern "C" signed char D_004E1D88;
extern "C" V4 D_004E1D90;
/* Inlined cVector_GetZero: lazily zeroed shared vector. */
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
static inline __int128 GL(const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=&r"(q) : "r"(s) : "memory"); return q; }
/* Inlined getter with a default: the -1 temporary is materialized only in the null arm. */
static inline const int* Id(const R* p) {
    int t;
    const int* r;
    if (p) r = &p->d;
    else { t = -1; r = &t; }
    return r;
}
/* Resets the vector to zero, m10 to 0 and m14 to -1. */
extern "C" T* cActivationTracker_ctor(T* d)
{
    *(__int128*)&d->q = GL(Vec4_Zero());
    d->m14 = -1;
    d->m10 = 0;
    d->m14 = *Id(0);
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001364B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001364B0 */
