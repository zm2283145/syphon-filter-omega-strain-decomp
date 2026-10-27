/*
 * SFOGame/Source/AgentData: 7 files, 0032F820-0032FBD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032F820 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Objective registration table iterator helpers (24-byte rows).
 */

#include "types.h"
#include "AgentData_types.h"

/* end() of the registration row vector. */
ObjectiveRow* std_vector_imp_RatingRecord_end(ObjectiveRowVec* v) {
    return v->data + v->count;
}

void std_vector_RatingRecord_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() of the registration row vector. */
ObjectiveRow* std_vector_imp_RatingRecord_begin(ObjectiveRowVec* v) {
    return v->data;
}
static inline void merge_flush_func_0032F820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F820 */

/* merge_units: begin func_0032F860 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma opt_propagation off
union ScriptArg { int i; float f; void* p; };
struct Tab2F860 { int a; int count; int c; int d; };
struct Ent2F860 { unsigned char flag; char pad[19]; };
struct List2F860 { Ent2F860* p; int x; int y; int z; };
struct Agent2F860 { char pad[0xAB0]; List2F860 lists[4]; };
extern "C" {
extern Tab2F860 D_00532A70[];
}

static inline unsigned char All2F860(Agent2F860* a, unsigned char kind)
{
    int i = 0;
    Tab2F860* t = &D_00532A70[kind];
    int n = t->count;
    if (0 < n) {
        List2F860* l = &a->lists[kind];
        Ent2F860* p = l->p;
        do {
            if (!p[i].flag) return 0;
            i++;
        } while (i < n);
    }
    return 1;
}

extern "C" int Script_cAgentData_HasAllSpecialRatings(ScriptArg* args)
{
    Agent2F860* a = (Agent2F860*)args[0].p;
    int t = 0;
    return All2F860(a, t);
}
static inline void merge_flush_func_0032F860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F860 */

/* merge_units: begin func_0032F8E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (ratings, commendations, omega).
 */


extern int D_00532AB8;
extern unsigned char cAgentData_HasCommendation(cAgentData* agent, int id);
extern unsigned char cAgentData_HasRating(cAgentData* agent, int id);
extern unsigned char cAgentData_HasSpecialRating(cAgentData* agent, int id);
extern int cAgentData_UpdateAchievement(cAgentData* agent, unsigned char* flag, int key, int unk);

int Script_cAgentData_HasSpecialRating(AgentScriptArg* args) {
    int id[1];
    id[0] = args[1].i;
    return cAgentData_HasSpecialRating(args[0].p, STACK_COPY(id));
}

int Script_cAgentData_HasCommendation(AgentScriptArg* args) {
    int id[1];
    id[0] = args[1].i;
    return cAgentData_HasCommendation(args[0].p, STACK_COPY(id));
}

int Script_cAgentData_HasRating(AgentScriptArg* args) {
    int id[1];
    id[0] = args[1].i;
    return cAgentData_HasRating(args[0].p, STACK_COPY(id));
}

/* Updates the omega flag through cAgentData_UpdateAchievement, then reports whether it is set. */
int Script_cAgentData_HasOmega(AgentScriptArg* args) {
    cAgentData* agent = args[0].p;
    unsigned char* omega = agent->omega;
    int has;
    cAgentData_UpdateAchievement(agent, omega, D_00532AB8, 0);
    has = omega ? *omega != 0 : 0;
    return has != 0;
}
static inline void merge_flush_func_0032F8E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F8E0 */

/* merge_units: begin func_0032F9C0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef union ScriptArg2F9C0 { int i; float f; void* p; } ScriptArg2F9C0;
typedef struct Lookup2F9C0 { void* name; int pad[5]; } Lookup2F9C0;
typedef struct Pair2F9C0 { int a; int b; } Pair2F9C0;
typedef struct Rec2F9C0 { int value; int pad[7]; } Rec2F9C0;
typedef struct Agent2F9C0 { char p0[0xC8]; int count; Rec2F9C0* recs; } Agent2F9C0;
extern Lookup2F9C0* D_00532AF8;
extern Pair2F9C0* D_00532B98;
extern void* nGlobalization_GetStringTag(void* name);
extern int String_CompareNoCase(void* a, void* b);

static inline unsigned char Has2F9C0(Agent2F9C0* ag, void* name)
{
    int i;
    for (i = 0; i < ag->count; i++) {
        if (String_CompareNoCase(nGlobalization_GetStringTag(D_00532AF8[i].name), name) == 0) {
            int v = ag->recs[i].value;
            if (v > 0 && v <= ((int*)D_00532B98)[i * 2]) return 1;
        }
    }
    return 0;
}

/* Script: true when the agent has a positive rating for the named entry within its solo limit. */
int Script_cAgentData_HasSoloPartime(ScriptArg2F9C0* args)
{
    int name[1];
    Agent2F9C0* ag = (Agent2F9C0*)args[0].p;
    name[0] = args[1].i;
    return Has2F9C0(ag, *(void**)name);
}
static inline void merge_flush_func_0032F9C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F9C0 */

/* merge_units: begin func_0032FAB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (medals).
 */


extern unsigned char cAgentData_HasMedal(cAgentData* agent, int medal);

int Script_cAgentData_HasMedal(AgentScriptArg* args) {
    int medal[1];
    medal[0] = args[1].i;
    return cAgentData_HasMedal(args[0].p, STACK_COPY(medal));
}
static inline void merge_flush_func_0032FAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FAB0 */

/* merge_units: begin func_0032FAE0 */
#pragma push /* merge_units */
/*
 * Script_cAgentData_HasRank: true when the highest rank reachable with the
 * agent's total points has the given name.
 */

/* Rank registry row (0x24 bytes). */
typedef struct RankRow {
    char* name;
    int unk04;
    int points;
    char pad0C[0x24 - 0xC];
} RankRow;

/* Rank registry vector (PtrVec layout). */
typedef struct RankVec {
    int unk0;
    int count;
    RankRow* data;
} RankVec;

extern RankVec g_RankRows;
extern int cAgentData_GetClearancePoints(cAgentData* agent);
extern int strcmp(const char*, const char*);

static inline unsigned char HasRank(cAgentData* agent, char* name) {
    int pts;
    int best;
    int bestPts;
    int i;
    pts = cAgentData_GetClearancePoints(agent);
    best = -1;
    bestPts = 0;
    for (i = 0; i < g_RankRows.count; i++) {
        if (pts >= g_RankRows.data[i].points && g_RankRows.data[i].points >= bestPts) {
            bestPts = g_RankRows.data[i].points;
            best = i;
        }
    }
    if (best > -1 && strcmp(g_RankRows.data[best].name, name) == 0)
        return 1;
    return 0;
}

#pragma opt_strength_reduction off
int Script_cAgentData_HasRank(AgentScriptArg* args) {
    cAgentData* agent = args[0].p;
    int name[1];
    name[0] = args[1].i;
    return HasRank(agent, (char*)STACK_COPY(name));
}
static inline void merge_flush_func_0032FAE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FAE0 */

/* merge_units: begin func_0032FBD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (objective bits and statistics).
 */


extern unsigned char cAgentData_IsObjectiveComplete(cAgentData* agent, int key);
extern int cAgentData_AddObjective(cAgentData* agent, int key, int global);
extern unsigned char cAgentData_AreObjectivesComplete(cAgentData* agent, int keys);

int Script_cAgentData_AreObjectivesComplete(AgentScriptArg* args) {
    int keys[1];
    keys[0] = args[1].i;
    return cAgentData_AreObjectivesComplete(args[0].p, STACK_COPY(keys));
}

int Game_IsObjectiveComplete(AgentScriptArg* args) {
    int key[1];
    key[0] = args[1].i;
    return cAgentData_IsObjectiveComplete(args[0].p, STACK_COPY(key));
}

/* AgentData.AddObjective(key): sets the objective bit without the multiplayer message. */
int AgentData_AddObjective(AgentScriptArg* args) {
    int key[1];
    key[0] = args[1].i;
    cAgentData_AddObjective(args[0].p, STACK_COPY(key), 0);
    return 0;
}

/* Returns statistic args[1] (0 when out of range); volatile mirrors the stack temporary. */
int Script_cAgentData_GetStat(AgentScriptArg* args) {
    unsigned char stat = args[1].u8;
    cAgentData* agent = args[0].p;
    volatile int value = stat < AGENT_STAT_COUNT ? agent->stats[stat] : 0;
    return value;
}
static inline void merge_flush_func_0032FBD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FBD0 */
