/*
 * main/particle: range (2 files, 003983E0-00398410)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "particle_types.h"

/* merge_units: begin func_003983E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * ParticleRelFlag constructor.
 */


extern Rel* std_vector_imp_intPtr_1_ctor(Rel* r);

ParticleRelFlag* cArray_intPtr_ctor(ParticleRelFlag* self) {
    std_vector_imp_intPtr_1_ctor(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003983E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003983E0 */

/* merge_units: begin func_00398410 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Rel initializers and pointer vector push_back.
 */


extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* Zeroes the three words. */
Rel* std_vector_imp_intPtr_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* push_back on a pointer vector. */
int std_vector_intPtr_push_back(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

/* Zeroes the three words. */
Rel* std_vector_cEffectRequestPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00398410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00398410 */
