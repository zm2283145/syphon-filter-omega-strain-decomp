/*
 * SFOGame/Source/AgentData: 1 file, 00336A30
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
