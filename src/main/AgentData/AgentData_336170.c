/*
 * main/AgentData: range (2 files, 00336170-003361B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "AgentData_types.h"

/* merge_units: begin func_00336170 */
#pragma push /* merge_units */
extern void* D_004FFC04;
extern void* func_002C90F0(void*);
/* Returns the global lookup result if set, else the object's embedded member at +0x8AC. */
void* func_00336170(char* p) { void* r = func_002C90F0(D_004FFC04); if (r) return r; return p + 0x8AC; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336170 */

/* merge_units: begin func_003361B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData reset.
 */


extern int AgentData_Reset(cAgentData* agent);

/* Full reset plus three additional flag bytes. */
int func_003361B0(cAgentData* agent) {
    int result = AgentData_Reset(agent);
    agent->unk8AC = 0;
    agent->unk8BC = 0;
    agent->unk8CC = 0;
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003361B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003361B0 */
