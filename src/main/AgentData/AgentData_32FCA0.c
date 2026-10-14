/*
 * main/AgentData: range (2 files, 0032FCA0-0032FCD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0032FCA0 */
#pragma push /* merge_units */
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { int p0, p4; int stats[1]; } A2FCA0;
static inline void Set2FCA0(A2FCA0* s, int i, int v) { s->stats[i] = v; }
#pragma opt_propagation off
int Script_cAgentData_SetStat(ScriptArg* args)
{
    int v[1];
    v[0] = args[2].i;
    Set2FCA0((A2FCA0*)args[0].p, args[1].b, *(int*)v);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FCA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FCA0 */

/* merge_units: begin func_0032FCD0 */
#pragma push /* merge_units */
typedef struct { int p0, p4; int stats[18]; int level[1]; } A2FCD0;
int Script_cAgentData_AddScore(ScriptArg* args)
{
    A2FCD0* self;
    int val;
    int idx;
    int v[1];
    v[0] = args[2].i;
    val = *(int*)v;
    idx = args[1].b;
    self = (A2FCD0*)args[0].p;
    if (idx < 31 && val > 0) {
        self->stats[idx] += val;
        if (idx < 13)
            self->level[idx] += val;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FCD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FCD0 */
