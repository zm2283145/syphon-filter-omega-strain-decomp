/*
 * SFOGame/Source/AgentData: 10 files, 0032F220-0032F560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032F220 */
#pragma push /* merge_units */
#include "types.h"
#include "scriptUtils_types.h"
#include "AgentData_types.h"

extern void cAgentData_UnlockRequirement(void*, int, int);

/* Script: cAgentData.UnlockBonusLevelReq(value). */
int Script_cAgentData_UnlockBonusLevelReq(ScriptArg* args) {
    int value[1]; /* staged through the stack */
    value[0] = args[1].i;
    cAgentData_UnlockRequirement(args[0].p, 3, *(int*)value);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F220(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F220 */

/* merge_units: begin func_0032F250 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cAgentData_UnlockRequirement(int agent, int kind, int value);
#endif /* merge_units */
#define cAgentData_UnlockRequirement(a0, a1, a2) (cAgentData_UnlockRequirement((void *)(a0), (a1), (a2))) /* merge_units */


/* Script: cAgentData.UnlockOmegaRequirement(agent, value). */
int Script_cAgentData_UnlockOmegaRequirement(int* args)
{
    int part[1]; /* staged through the stack */
    part[0] = args[1];
    cAgentData_UnlockRequirement(args[0], 4, *(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F250(void) {}
#undef cAgentData_UnlockRequirement /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F250 */

/* merge_units: begin func_0032F280 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cAgentData_UnlockRequirement(void* agent, int unlock, int req);
#endif /* merge_units */
#define cAgentData_UnlockRequirement(a0, a1, a2) (cAgentData_UnlockRequirement((a0), (a1), (a2))) /* merge_units */



/* Script native: cAgentData.UnlockCommendationReq(agent, req). */
int Script_cAgentData_UnlockCommendationReq(ScriptArg* args) {
    int part[1]; /* staged through the stack */
    part[0] = args[1].i;
    cAgentData_UnlockRequirement(args[0].p, 1, *(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F280(void) {}
#undef cAgentData_UnlockRequirement /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F280 */

/* merge_units: begin func_0032F2B0 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg_0032F2B0;

#if 0 /* merge_units */
extern void cAgentData_UnlockRequirement(void* agent, int kind, int index);
#endif /* merge_units */
#define cAgentData_UnlockRequirement(a0, a1, a2) (cAgentData_UnlockRequirement((a0), (a1), (a2))) /* merge_units */



/* Script native: unlocks a special-rating requirement (kind 0) of the agent data. */
int Script_cAgentData_UnlockSpecialRatingReq(ScriptArg_0032F2B0* args)
{
    int index[1];
    index[0] = args[1].i;
    cAgentData_UnlockRequirement(args[0].p, 0, *(int*)index);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F2B0(void) {}
#undef cAgentData_UnlockRequirement /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F2B0 */

/* merge_units: begin func_0032F2E0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cAgentData_UnlockRequirement(void* agentData, int kind, int medal);
#endif /* merge_units */
#define cAgentData_UnlockRequirement(a0, a1, a2) (cAgentData_UnlockRequirement((a0), (a1), (a2))) /* merge_units */


/* Script native: unlocks medal requirement args[1] on agent data args[0]; returns 0. */
int Script_cAgentData_UnlockMedalRequirement(ScriptArg* args)
{
    int medal[1];
    medal[0] = args[1].i;
    cAgentData_UnlockRequirement(args[0].p, 2, *(int*)medal);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F2E0(void) {}
#undef cAgentData_UnlockRequirement /* merge_units */
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

/* merge_units: begin func_0032F340 */
#pragma push /* merge_units */
#pragma cplusplus on
union ScriptArg2F340 { int i; float f; void* p; };
struct Z2F340 { signed char a, b, c, d; };
struct A2F340 { char p0[0xD8]; int count; Z2F340 z[1]; char pad[0xB72 - 0xE0]; unsigned char dirty; };
/* Script: removes the matching zeus unlock entry (stage, level-1, mission-1) from the agent. */
extern "C" int Script_cAgentData_LockZeus(ScriptArg2F340* args)
{
    int c[1];
int b[1];
int a[1];
    int av;
int bv;
int cv;
    A2F340* ag;
    int i;
    c[0] = args[3].i;
    cv = *(int*)c;
    b[0] = args[2].i;
    bv = *(int*)b;
    a[0] = args[1].i;
    av = *(int*)a;
    ag = (A2F340*)args[0].p;
    for (i = 0; i < *(volatile int*)&ag->count; i++) {
        Z2F340* z = &ag->z[i];
        if (z->a == av && z->b == bv - 1 && z->c == cv - 1) {
            ag->count--;
            *(Z2F340*)((char*)ag + (i << 2) + 0xDC) = ag->z[ag->count];
            ag->dirty = 1;
            break;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F340 */

/* merge_units: begin func_0032F420 */
#pragma push /* merge_units */
#pragma cplusplus on
union ScriptArg2F420 { int i; float f; void* p; };
struct Z2F420 { signed char a, b, c, d; };
struct A2F420 { char p0[0xD8]; int count; Z2F420 z[1]; char pad[0xB72 - 0xE0]; unsigned char dirty; };
static inline unsigned char Has2F420(A2F420* ag, int av, int bv, int cv)
{
    int i;
    for (i = 0; i < *(volatile int*)&ag->count; i++) {
        Z2F420* z = &ag->z[i];
        if (z->a == av && z->b == bv - 1 && z->c == cv - 1) return 1;
    }
    return 0;
}
/* Script: adds the zeus unlock entry (stage, level-1, mission-1) unless already present. */
extern "C" int Script_cAgentData_UnlockZeus(ScriptArg2F420* args)
{
    int c[1];
int b[1];
int a[1];
    A2F420* ag;
int av;
int bv;
int cv;
    c[0] = args[3].i;
    cv = *(int*)c;
    b[0] = args[2].i;
    bv = *(int*)b;
    a[0] = args[1].i;
    av = *(int*)a;
    ag = (A2F420*)args[0].p;
    if (!Has2F420(ag, av, bv, cv)) {
        Z2F420* z = (Z2F420*)((char*)ag + (ag->count++ << 2) + 0xDC);
        z->a = av;
        z->b = bv - 1;
        z->c = cv - 1;
        z->d = 0;
        ag->dirty = 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F420 */

/* merge_units: begin func_0032F510 */
#pragma push /* merge_units */
typedef union ScriptArg_0032F510 { int i; float f; void* p; unsigned char b; } ScriptArg_0032F510;
typedef struct { char pad[0xB08]; unsigned int bits[1]; } A2F510;
int Script_cAgentData_UnlockSpecial(ScriptArg_0032F510* args)
{
    int i = args[1].b;
    A2F510* self = (A2F510*)args[0].p;
    if (i > -1)
        self->bits[i / 32] |= 1 << (i & 31);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F510 */

/* merge_units: begin func_0032F560 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (unlocks, objective queries, bonus levels).
 */


extern unsigned char cAgentData_IsObjectiveComplete(cAgentData* agent, int key);
extern int g_HumanActorClassKey;
extern AgentGObj* cGOBJ_SOBJ_convert(int handle);
extern unsigned char Global_IsObjectiveComplete(AgentGObj* gobj, int key);
extern unsigned char cAgentData_HasBonusLevel(cAgentData* agent, int level);
extern void cAgentData_UnlockLevel(cAgentData* agent, int level);
extern void cAgentData_UnlockWeapon(cAgentData* agent, int weapon);
extern cAgentData* cHuman_GetAgentData(AgentGObj* gobj);

int Script_cAgentData_UnlockWeapon(AgentScriptArg* args) {
    int weapon[1];
    weapon[0] = args[1].i;
    cAgentData_UnlockWeapon(args[0].p, STACK_COPY(weapon));
    return 0;
}

int Script_cAgentData_UnlockLevel(AgentScriptArg* args) {
    int level[1];
    level[0] = args[1].i;
    cAgentData_UnlockLevel(args[0].p, STACK_COPY(level));
    return 0;
}

/* game::IsObjectiveComplete(gobj, key); the volatile local mirrors the stack temporary. */
int Script_IsObjectiveComplete(AgentScriptArg* args) {
    volatile int key = args[1].i;
    AgentGObj* gobj = cGOBJ_SOBJ_convert(args[0].i);
    return Global_IsObjectiveComplete(gobj, key);
}

/* Queries the agent data of an object of the agent class; other objects report false. */
unsigned char Global_IsObjectiveComplete(AgentGObj* gobj, int key) {
    if (gobj->classKey == g_HumanActorClassKey) {
        return cAgentData_IsObjectiveComplete(cHuman_GetAgentData(gobj), key);
    }
    return 0;
}

int Script_cAgentData_HasBonusLevel(AgentScriptArg* args) {
    int level[1];
    level[0] = args[1].i;
    return cAgentData_HasBonusLevel(args[0].p, STACK_COPY(level));
}
static inline void merge_flush_func_0032F560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F560 */
