/*
 * main/npc: range (3 files, 0014B100-0014B1E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_0014B100 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(func_0014B100, D_004D9360, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0014B100 */

/* merge_units: begin func_0014B160 */
#pragma push /* merge_units */
typedef struct { float m[3][4]; } R_B160;
typedef struct { __int128 q; } V_B160;
typedef struct { float m[3][4]; V_B160 p; } M_B160;
#pragma peephole off
M_B160* cMatrix_ctor_cMatrixR_cVectorR(M_B160* self, R_B160* r, V_B160* p)
{
    self->m[0][0] = r->m[0][0];
    self->m[0][1] = r->m[0][1];
    self->m[0][2] = r->m[0][2];
    self->m[1][0] = r->m[1][0];
    self->m[1][1] = r->m[1][1];
    self->m[1][2] = r->m[1][2];
    self->m[2][0] = r->m[2][0];
    self->m[2][1] = r->m[2][1];
    self->m[2][2] = r->m[2][2];
    self->m[0][3] = r->m[0][3];
    self->m[1][3] = r->m[1][3];
    self->m[2][3] = r->m[2][3];
    self->p = *p;
    return self;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B160 */

/* merge_units: begin func_0014B1E0 */
#pragma push /* merge_units */
#pragma peephole off
#pragma opt_common_subs off
#pragma opt_propagation off
Vec4 cVector_Copy_WSet1(Vec4* src)
{
    Vec4 t;
    Vec4* p;
    t = *src;
    p = &t;
    p->w = 1.0f;
    return *p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B1E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B1E0 */
