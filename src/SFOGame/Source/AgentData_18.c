/*
 * SFOGame/Source/AgentData: 5 files, 00336A30-00336A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00336A30 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Deleting destructor: destroy the member at +4, then delete. */
extern "C" void operator_delete(void* allocation);
extern "C" void* std_vector_eRequirementState_dtor(void* self, short deleteFlag);

typedef struct { int pad0; int member; } Obj_00336A30;

extern "C" Obj_00336A30* cAgentData_tAchievement_dtor(Obj_00336A30* self, short deleteFlag)
{
    if (self) {
        void* m = &self->member;
        if (m)
            std_vector_eRequirementState_dtor(m, -1);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00336A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336A30 */

/* merge_units: begin func_00336A90 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "owned_buffer8_dtor_deep.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

#pragma cplusplus on

extern "C" {
char D_004B99B8[] = "allocator.hh";
}
DEFINE_OWNED_BUFFER8_DTOR_DEEP(std_vector_eRequirementState_dtor, D_004B99B8)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336A90 */

/* merge_units: begin func_00336B80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cBitArray_224_dtor)
static inline void merge_flush_func_00336B80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336B80 */

/* merge_units: begin func_00336BD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector helper.
 */

#include "AgentData_types.h"

extern int std_vector_pod_eAchievementState_insert(ByteVec* v, char* pos, int n, int value);

/* push_back(value) */
int std_vector_eAchievementState_push_back(ByteVec* v, int value) {
    return std_vector_pod_eAchievementState_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00336BD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336BD0 */

/* merge_units: begin func_00336BF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nested_null_dtor.h"

DEFINE_NESTED_NULL_DTOR2(cArray_eRequirementState_dtor, std_vector_imp_eRequirementState_1_dtor)
static inline void merge_flush_func_00336BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00336BF0 */
