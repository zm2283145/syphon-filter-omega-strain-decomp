/*
 * SFOGame/Source/AgentData: 4 files, 00333170-003334C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00333170 */
#pragma push /* merge_units */
/*
 * cAgentData_FindRequirement: finds the range definition of table D_00532A70[type] that
 * contains the localised key and returns the matching byte of the agent's
 * per-type record (used by cAgentData_UnlockRequirement to set a flag byte).
 */

/* Range definition (24 bytes). */
typedef struct RangeDef {
    int unk00;
    int unk04;
    int start;
    int len;
    int unk10;
    int unk14;
} RangeDef;

/* Global definition table per type (16 bytes, PtrVec layout). */
typedef struct RangeTable {
    int unk00;
    int count;
    RangeDef* data;
    int unk0C;
} RangeTable;

/* Agent-side record (20 bytes). */
typedef struct RangeRec {
    char pad00[0xC];
    unsigned char* bytes;
    int unk10;
} RangeRec;

typedef struct RangeRecVec {
    int unk00;
    int count;
    RangeRec* data;
    int unk0C;
} RangeRecVec;

typedef struct AgentRanges {
    char pad00[0xAA8];
    RangeRecVec recs[5];
} AgentRanges;

extern RangeTable D_00532A70[5];
extern int nGlobalization_GetStringIndex(const char* key);

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
unsigned char* cAgentData_FindRequirement(AgentRanges* self, unsigned char type, const char* key) {
    int k = nGlobalization_GetStringIndex(key);
    int i;
    int s;
    int l;
    RangeTable* t;
    RangeDef* defs;
    int* pc;
    i = 0;
    if (i < D_00532A70[type].count) {
        t = &D_00532A70[type];
        defs = t->data;
        pc = &t->count;
        do {
            RangeDef* d = defs + i;
            s = d->start;
            l = d->len;
            if (k >= s && k < s + l) {
                RangeRecVec* rv = &self->recs[type];
                return (*(RangeRec(*)[])rv->data)[i].bytes + (k - s);
            }
            i++;
        } while (i < *pc);
    }
    return 0;
}
static inline void merge_flush_func_00333170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00333170 */

/* merge_units: begin func_00333260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* cAgentData_GetRequirements: fills `out` with the award items of group `idx` of award type
 * `type`: for type 4 the shared item table entries (with the group's states), otherwise one
 * item per element built from its localisation key; type 4 also appends the closing item once
 * the agent's award element completes. */
struct Item { char* text; void* name; char state; int a; int b; int c; int agent; };
struct IV { int a; int count; Item* data; };
struct Grp { int a; int b; int count; char* states; int pad; };
struct TEnt { int a; int b; char* names; int pad[3]; };
struct TType { int a; int b; TEnt* ents; int pad; };
struct AwardP { unsigned char done; };
struct AgentAw { char pad[0xAB0]; struct { Grp* grps; int pad[3]; } type[4]; AwardP* elem; };
extern "C" {
#if 0 /* merge_units */
extern TType D_00532A70[];
#endif /* merge_units */
#define D_00532A70 ((TType*)&D_00532A70) /* merge_units */

extern Item* D_00532BB8;
extern int D_00532BB4;
extern void* D_00532AB8;
void func_00299500(IV* v);
void* nGlobalization_GetStringTag(void* name);
char* nGlobalization_GetString_charP(void* name);
#if 0 /* merge_units */
int nGlobalization_GetStringIndex(int k);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((const char *)(a0))) /* merge_units */

int cAgentData_GetWpnIndex(int k);
void std_vector_imp_tRequirementInfo_insert(IV* v, Item* pos, int n, Item* val);
void cAgentData_UpdateAchievement(void* self, AwardP* p, void* q, int force);
void cAgentData_GetRequirements(AgentAw* a, unsigned char type, int idx, IV* out);
}
#pragma opt_strength_reduction off
static inline bool IsDone(AwardP* p) { bool r = false; if (p) r = p->done != 0; return r; }
extern "C" void cAgentData_GetRequirements(AgentAw* a, unsigned char type, int idx, IV* out)
{
    Grp* g;
    int i;
    g = &((AgentAw*)a)->type[type].grps[idx]; /* the cast gives retail's a+off add order */
    func_00299500(out);
    for (i = 0; i < g->count; i++) {
        Item item;
        Item* ip;
        if (type == 4) {
            ip = &D_00532BB8[i];
            ip->state = g->states[i];
        } else {
            void* name;
            int off = idx * sizeof(TEnt);
            char st = g->states[i];
            name = nGlobalization_GetStringTag(((TEnt*)((char*)D_00532A70[type].ents + off))->names + i);
            item.text = nGlobalization_GetString_charP(name);
            item.name = name;
            item.state = st;
            void* k = 0;
            item.agent = k ? cAgentData_GetWpnIndex(nGlobalization_GetStringIndex(0)) : -1;
            item.a = 0;
            item.b = 0;
            item.c = 0;
            ip = &item;
        }
        std_vector_imp_tRequirementInfo_insert(out, &out->data[out->count], 1, ip);
    }
    if (type == 4) {
        AwardP* p = a->elem;
        cAgentData_UpdateAchievement(a, p, D_00532AB8, 0);
        if (IsDone(p)) {
            Item* it = &D_00532BB8[D_00532BB4 - 1];
            it->state = 2;
            std_vector_imp_tRequirementInfo_insert(out, &out->data[out->count], 1, it);
        }
    }
}
#undef D_00532A70 /* merge_units */
#undef nGlobalization_GetStringIndex /* merge_units */
static inline void merge_flush_func_00333260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00333260 */

/* merge_units: begin func_003334C0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct RangeDef4C0 {
    int key;
    int unk04;
    int start;
    int len;
    int value;
    int unk14;
} RangeDef4C0;

typedef struct RangeTable4C0 {
    int unk00;
    int count;
    RangeDef4C0* data;
    int unk0C;
} RangeTable4C0;

typedef struct RangeRec4C0 {
    signed char flag;
    char pad01[0x13];
} RangeRec4C0;

typedef struct RangeRecVec4C0 {
    int unk00;
    int count;
    RangeRec4C0* data;
    int unk0C;
} RangeRecVec4C0;

typedef struct Agent4C0 {
    char pad00[0xAA8];
    RangeRecVec4C0 recs[5];
} Agent4C0;

typedef struct Out4C0 {
    int text;
    int key;
    signed char flag;
    int value;
    int unk10;
} Out4C0;

typedef struct OutVec4C0 {
    int unk00;
    int count;
    Out4C0* data;
} OutVec4C0;

#if 0 /* merge_units */
extern RangeTable4C0 D_00532A70[5];
#endif /* merge_units */
#define D_00532A70 ((RangeTable4C0*)&D_00532A70) /* merge_units */

extern void std_vector_deleter_tAchievementInfo_clear(OutVec4C0* v);
extern int nGlobalization_GetString_int(int id);
extern int std_vector_imp_tAchievementInfo_insert(OutVec4C0* v, Out4C0* pos, int n, Out4C0* value);

void cAgentData_GetAchievements(Agent4C0* self, unsigned char type, OutVec4C0* out)
{
    RangeRecVec4C0* recs = &self->recs[type];
    int i;
    std_vector_deleter_tAchievementInfo_clear(out);
    for (i = 0; i < recs->count; i++) {
        Out4C0 e;
        RangeDef4C0* d = &D_00532A70[type].data[i];
        signed char flag;
        int value;
        int key;
        value = d->value;
        key = d->key;
        flag = recs->data[i].flag;
        e.text = nGlobalization_GetString_int(key);
        e.key = key;
        e.flag = flag;
        e.value = value;
        e.unk10 = 0;
        std_vector_imp_tAchievementInfo_insert(out, &out->data[out->count], 1, &e);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003334C0(void) {}
#undef D_00532A70 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003334C0 */

/* merge_units: begin func_00333600 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct Rating600 {
    int key;
    int unk04;
    unsigned char stat;
    char pad09[3];
    int min;
    int need;
    int value;
} Rating600;

typedef struct RatingVec600 {
    int unk00;
    int count;
    Rating600* data;
} RatingVec600;

typedef struct Agent600 {
    char pad00[0x08];
    int stats[1];
} Agent600;

typedef struct Out600 {
    int text;
    int key;
    signed char flag;
    int value;
    int pct;
} Out600;

typedef struct OutVec600 {
    int unk00;
    int count;
    Out600* data;
} OutVec600;

extern RatingVec600 D_00532AD0;
#if 0 /* merge_units */
extern void std_vector_deleter_tAchievementInfo_clear(OutVec600* v);
#endif /* merge_units */
#define std_vector_deleter_tAchievementInfo_clear(a0) (std_vector_deleter_tAchievementInfo_clear((OutVec4C0 *)(a0))) /* merge_units */


extern signed char* std_vector_eAchievementState_opIndex(void* bits, int i);
#if 0 /* merge_units */
extern int std_vector_imp_tAchievementInfo_insert(OutVec600* v, Out600* pos, int n, Out600* value);
#endif /* merge_units */
#define std_vector_imp_tAchievementInfo_insert(a0, a1, a2, a3) (std_vector_imp_tAchievementInfo_insert((OutVec4C0 *)(a0), (Out4C0 *)(a1), (a2), (Out4C0 *)(a3))) /* merge_units */



void cAgentData_GetRatings(Agent600* self, OutVec600* out)
{
    int i;
    std_vector_deleter_tAchievementInfo_clear(out);
    for (i = 0; i < D_00532AD0.count; i++) {
        Out600 e;
        int pct;
        signed char flag;
        int value;
        int key;
        Rating600* r = &D_00532AD0.data[i];
        int v = self->stats[r->stat];
        int need = r->need;
        pct = 0;
        if (v >= need) {
            pct = 100;
        } else if (r->min < v) {
            pct = (v - r->min) * 100 / (need - r->min);
        }
        value = r->value;
        flag = *std_vector_eAchievementState_opIndex(&self->stats[700], i);
        key = r->key;
        e.text = nGlobalization_GetString_int(key);
        e.key = key;
        e.flag = flag;
        e.value = value;
        e.pct = pct;
        std_vector_imp_tAchievementInfo_insert(out, &out->data[out->count], 1, &e);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333600(void) {}
#undef std_vector_deleter_tAchievementInfo_clear /* merge_units */
#undef std_vector_imp_tAchievementInfo_insert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00333600 */
