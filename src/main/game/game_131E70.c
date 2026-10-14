/*
 * main/game: range (3 files, 00131E70-00131F00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "game_types.h"

/* merge_units: begin func_00131E70 */
#pragma push /* merge_units */
#pragma peephole off
#pragma opt_common_subs off
typedef struct { Vec4 r[3]; Vec4 t; } Mtx;
/* Sets the translation row (+0x30) of a matrix and returns it. */
Mtx* Mtx_SetTranslation(Mtx* m, Vec4* t) { m->t = *t; return m; }
#pragma opt_common_subs reset
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00131E70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00131E70 */

/* merge_units: begin func_00131E90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Sets the three rows of a 3x4 matrix from three 4-float vectors. */
Mtx34* Mtx_SetBasis(Mtx34* m, Float4* r0, Float4* r1, Float4* r2) {
    float w0 = r0->w, z0 = r0->z, y0 = r0->y, x0 = r0->x;
    float w1, z1, y1, x1;
    float w2, z2, y2, x2;

    m->row[0].x = x0;
    m->row[0].y = y0;
    m->row[0].z = z0;
    m->row[0].w = w0;
    w1 = r1->w; z1 = r1->z; y1 = r1->y; x1 = r1->x;
    m->row[1].x = x1;
    m->row[1].y = y1;
    m->row[1].z = z1;
    m->row[1].w = w1;
    w2 = r2->w; z2 = r2->z; y2 = r2->y; x2 = r2->x;
    m->row[2].x = x2;
    m->row[2].y = y2;
    m->row[2].z = z2;
    m->row[2].w = w2;
    return m;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00131E90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00131E90 */

/* merge_units: begin func_00131F00 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct Obj40 {
    char pad[0x30];
    Q q;
} Obj40;

extern void Mtx_SetRow0(Obj40*);
extern void Mtx_SetRow1(Obj40*, int);
extern void Mtx_SetRow2(Obj40*, int);

/* Constructor: base init, two setters, then copies a vector to +0x30. */
Obj40* Mtx_FromRowsAndTranslation(Obj40* o, int unused, int a, int b, Q* q) {
    Mtx_SetRow0(o);
    Mtx_SetRow1(o, a);
    Mtx_SetRow2(o, b);
    o->q = *q;
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00131F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00131F00 */
