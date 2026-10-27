/*
 * main/AgentData: range (4 files, 0032F130-0032F1C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0032F130 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg;

extern void cAgentData_CompleteRequirement(void* agent, int kind, int index);

/* Script native: completes a bonus-level requirement (kind 3) of the agent data. */
int Script_cAgentData_CompleteBonusLevelReq(ScriptArg* args)
{
    int index[1];
    index[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 3, *(int*)index);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F130 */

/* merge_units: begin func_0032F160 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cAgentData_CompleteRequirement(void* agent, int kind, int value);
#endif /* merge_units */
#define cAgentData_CompleteRequirement(a0, a1, a2) (cAgentData_CompleteRequirement((a0), (a1), (a2))) /* merge_units */


typedef union { int i; void* p; float f; } ScriptArg_0032F160;

/* Script native: completes an Omega requirement (kind 4) on the agent data. */
int Script_cAgentData_CompleteOmegaReq(ScriptArg_0032F160* args)
{
    int p1[1];
    p1[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 4, *(int*)p1);
    return 0;
}
#undef cAgentData_CompleteRequirement /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F160 */

/* merge_units: begin func_0032F190 */
#pragma push /* merge_units */
typedef union ScriptArg_0032F190 { int i; float f; void* p; } ScriptArg_0032F190;
#if 0 /* merge_units */
extern void cAgentData_CompleteRequirement(void* agent, int a1, int requirement);
#endif /* merge_units */
#define cAgentData_CompleteRequirement(a0, a1, a2) (cAgentData_CompleteRequirement((a0), (a1), (a2))) /* merge_units */


/* Script native: completes commendation requirement args[1] for agent data args[0]. */
int Scr_cAgentData_CompleteCommendationReq(ScriptArg_0032F190* args)
{
    int part[1];
    part[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 1, *(int*)part);
    return 0;
}
#undef cAgentData_CompleteRequirement /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F190 */

/* merge_units: begin func_0032F1C0 */
#pragma push /* merge_units */
typedef union ScriptArg_0032F1C0 { int i; float f; void* p; } ScriptArg_0032F1C0;
#if 0 /* merge_units */
extern void cAgentData_CompleteRequirement(void* agent, int a1, int requirement);
#endif /* merge_units */
#define cAgentData_CompleteRequirement(a0, a1, a2) (cAgentData_CompleteRequirement((a0), (a1), (a2))) /* merge_units */


/* Script native: completes special rating requirement args[1] for agent data args[0]. */
int Scr_cAgentData_CompleteSpecialRatingReq(ScriptArg_0032F1C0* args)
{
    int part[1];
    part[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 0, *(int*)part);
    return 0;
}
#undef cAgentData_CompleteRequirement /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F1C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F1C0 */
