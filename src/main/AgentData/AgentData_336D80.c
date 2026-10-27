/*
 * main/AgentData: range (3 files, 00336D80-00336E40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "AgentData_types.h"

/* merge_units: begin func_00336D80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Small constructors / forwarding helpers.
 */


extern Rel* std_vector_imp_eRequirementState_1_ctor(Rel* r);
extern int std_vector_pod_eRequirementState_resize(int a0, int a1, int a2);

int cArray_eRequirementState_ResizeActual(int a0, int a1, int a2) {
    return std_vector_pod_eRequirementState_resize(a0, a1, a2);
}

/* Clears the three words and sets the flag. */
RelFlag* cArray_eRequirementState_ctor(RelFlag* self) {
    std_vector_imp_eRequirementState_1_ctor(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336D80 */

/* merge_units: begin func_00336DC0 */
#pragma push /* merge_units */
extern int std_vector_pod_int_reserve(int, int);
extern Rel* std_vector_imp_tAchievement_ctor(Rel* r);

Rel* std_vector_imp_eRequirementState_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_charPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_eAchievementState_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Clears the three words and sets the flag. */
RelFlag* cArray_tAchievement_ctor(RelFlag* self) {
    std_vector_imp_tAchievement_ctor(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336DC0 */

/* merge_units: begin func_00336E40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* std_vector_imp_tAchievement_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* std_vector_tMissionStats_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336E40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336E40 */
