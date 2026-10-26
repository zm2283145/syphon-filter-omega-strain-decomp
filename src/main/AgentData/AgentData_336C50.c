/*
 * main/AgentData: range (2 files, 00336C50-00336D40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "owned_buffer8_dtor_deep.h"
#pragma pop

/* merge_units: begin func_00336C50 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_OWNED_BUFFER8_DTOR_MID(std_vector_imp_eRequirementState_1_dtor, D_004B99B8)
#pragma pop /* merge_units */
/* merge_units: end func_00336C50 */

/* merge_units: begin func_00336D40 */
#pragma push /* merge_units */
typedef struct { char a; char pad[7]; int n; char* p; } B3_336D40;
void cAgentData_tAchievement_Reset(B3_336D40* s)
{
    int i;
    s->a = 0;
    for (i = 0; i < s->n; i++) {
        s->p[i] = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336D40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336D40 */
