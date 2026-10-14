/*
 * main/AgentData: range (6 files, 0032F220-0032F310)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptUtils_types.h"
#include "AgentData_types.h"

/* merge_units: begin func_0032F220 */
#pragma push /* merge_units */
extern void func_00333130(void*, int, int);

/* Script: cAgentData.UnlockBonusLevelReq(value). */
int Script_cAgentData_UnlockBonusLevelReq(ScriptArg* args) {
    int value[1]; /* staged through the stack */
    value[0] = args[1].i;
    func_00333130(args[0].p, 3, *(int*)value);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F220(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F220 */

/* merge_units: begin func_0032F250 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void func_00333130(int agent, int kind, int value);
#endif /* merge_units */
#define func_00333130(a0, a1, a2) (func_00333130((void *)(a0), (a1), (a2))) /* merge_units */

/* Script: cAgentData.UnlockOmegaRequirement(agent, value). */
int Script_cAgentData_UnlockOmegaRequirement(int* args)
{
    int part[1]; /* staged through the stack */
    part[0] = args[1];
    func_00333130(args[0], 4, *(int*)part);
    return 0;
}
#undef func_00333130 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F250 */

/* merge_units: begin func_0032F280 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void func_00333130(void* agent, int unlock, int req);
#endif /* merge_units */
#define func_00333130(a0, a1, a2) (func_00333130((a0), (a1), (a2))) /* merge_units */


/* Script native: cAgentData.UnlockCommendationReq(agent, req). */
int Script_cAgentData_UnlockCommendationReq(ScriptArg* args) {
    int part[1]; /* staged through the stack */
    part[0] = args[1].i;
    func_00333130(args[0].p, 1, *(int*)part);
    return 0;
}
#undef func_00333130 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F280 */

/* merge_units: begin func_0032F2B0 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg_0032F2B0;

#if 0 /* merge_units */
extern void func_00333130(void* agent, int kind, int index);
#endif /* merge_units */
#define func_00333130(a0, a1, a2) (func_00333130((a0), (a1), (a2))) /* merge_units */


/* Script native: unlocks a special-rating requirement (kind 0) of the agent data. */
int Script_cAgentData_UnlockSpecialRatingReq(ScriptArg_0032F2B0* args)
{
    int index[1];
    index[0] = args[1].i;
    func_00333130(args[0].p, 0, *(int*)index);
    return 0;
}
#undef func_00333130 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F2B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F2B0 */

/* merge_units: begin func_0032F2E0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void func_00333130(void* agentData, int kind, int medal);
#endif /* merge_units */
#define func_00333130(a0, a1, a2) (func_00333130((a0), (a1), (a2))) /* merge_units */

/* Script native: unlocks medal requirement args[1] on agent data args[0]; returns 0. */
int Script_cAgentData_UnlockMedalRequirement(ScriptArg* args)
{
    int medal[1];
    medal[0] = args[1].i;
    func_00333130(args[0].p, 2, *(int*)medal);
    return 0;
}
#undef func_00333130 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F2E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F2E0 */

/* merge_units: begin func_0032F310 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives.
 */


extern int cAgentData_UnlockPart(cAgentData* agent, int part);

int Script_cAgentData_UnlockPart(AgentScriptArg* args) {
    int part[1];
    part[0] = args[1].i;
    cAgentData_UnlockPart(args[0].p, STACK_COPY(part));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F310 */
