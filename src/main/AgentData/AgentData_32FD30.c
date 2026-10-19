/*
 * main/AgentData: range (2 files, 0032FD30-0032FD70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "AgentData_types.h"

/* merge_units: begin func_0032FD30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (clearance points).
 */


extern int AgentData_TotalPoints(cAgentData* agent);

/* Returns the agent's total clearance points; volatile mirrors the stack temporary. */
int Script_cAgentData_GetClearancePoints(AgentScriptArg* args) {
    volatile int points = AgentData_TotalPoints(args[0].p);
    return points;
}

void func_0032FD60(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FD30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FD30 */

/* merge_units: begin func_0032FD70 */
#pragma push /* merge_units */
typedef struct { int key; int a; char b; int c; int d; int e; } Medal;
extern int Loc_FindKeyThunk(const char* name);

/* Medal constructor: resolves the name key and stores the fields; id is 10000 + index. */
Medal* RatingRow_ConstructIndexed(Medal* self, const char* name, int a, char b, int c, int d, unsigned char index)
{
    self->key = Loc_FindKeyThunk(name);
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    self->e = index + 10000;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FD70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FD70 */
