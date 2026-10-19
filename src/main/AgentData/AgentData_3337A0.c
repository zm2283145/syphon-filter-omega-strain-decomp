/*
 * main/AgentData: range (6 files, 003337A0-00333B90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

/* merge_units: begin func_003337A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E337A0 { int id; int pad[4]; int val; };
extern "C" {
extern char g_UnlockRows[];
extern int D_00532B14;
E337A0** func_003305C0(void* v);
}
static inline bool Neq337A0(E337A0* a, E337A0* b) { return !(a == b); }
extern "C" int Awards_ResolveUnlock(int id)
{
    if (id > -1) {
        E337A0* first = *func_003305C0(g_UnlockRows);
        E337A0* last = *func_003305C0(g_UnlockRows) + D_00532B14;
        for (; Neq337A0(first, last); first++) {
            if (id == first->id)
                return first->val;
        }
    }
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003337A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003337A0 */

/* merge_units: begin func_00333860 */
#pragma push /* merge_units */
extern int Awards_FindRequirementRow(int, int, int);

void func_00333860(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    v0 = Awards_FindRequirementRow(a0, a1, a2);
    cond = v0 == 0;
    v1 = 0 + 2;
    if (cond) goto L00333880;
    *(char*)(char*)v0 = v1;
L00333880:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00333860 */

/* merge_units: begin func_00333890 */
#pragma push /* merge_units */
extern int String_ToLower(int c);

int Awards_MatchKeyPattern(void* self, const char* a, const char* b, char wild)
{
    int i = 0;
    int j = 0;
    while (a[i] != 0 && b[j] != 0 && a[i] != wild) {
        if (String_ToLower(a[i++]) != String_ToLower(b[j++])) return 0;
    }
    i = strlen(a);
    j = strlen(b);
    while (i >= 0 && j >= 0 && a[i] != wild) {
        if (String_ToLower(a[i--]) != String_ToLower(b[j--])) return 0;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333890(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00333890 */

/* merge_units: begin func_003339E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E3339E0 { int name; int idx; int pad[4]; };
struct A3339E0 { char pad[0x84]; int bits[8]; };
extern "C" {
extern char D_005329F0[];
extern int D_005329F4;
#if 0 /* merge_units */
E3339E0** func_003305C0(void* v);
#endif /* merge_units */
#define func_003305C0(a0) ((E3339E0 * *)func_003305C0((a0))) /* merge_units */

const char* Loc_GetStoredKey(int name);
#if 0 /* merge_units */
int Awards_MatchKeyPattern(A3339E0* self, const char* a, const char* b, char wild);
#endif /* merge_units */
#define Awards_MatchKeyPattern(a0, a1, a2, a3) (Awards_MatchKeyPattern((void *)(a0), (a1), (a2), (a3))) /* merge_units */

}
static inline bool Neq3339E0(E3339E0* a, E3339E0* b) { return !(a == b); }
static inline bool Done3339E0(A3339E0* self, int idx)
{
    int r;
    if (idx > -1) r = ((self->bits[idx / 32] >> (idx & 31)) & 1) != 0;
    else { r = 0; asm { .set reorder } }
    return r;
}
extern "C" int cAgentData_AreObjectivesComplete(A3339E0* self, const char* pattern)
{
    E3339E0* first = *func_003305C0(D_005329F0);
    E3339E0* last = *func_003305C0(D_005329F0) + D_005329F4;
    for (; Neq3339E0(first, last); first++) {
        if (Awards_MatchKeyPattern(self, pattern, Loc_GetStoredKey(first->name), '*')) {
            if (!Done3339E0(self, first->idx)) return 0;
        }
    }
    return 1;
}
#undef func_003305C0 /* merge_units */
#undef Awards_MatchKeyPattern /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003339E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003339E0 */

/* merge_units: begin func_00333B10 */
#pragma push /* merge_units */
typedef struct { char pad[0x84]; int bits[1]; } T333B10;
extern __int128 StringPool_MakeKey(int id);
extern int Objective_Find(__int128 key);
int AgentData_IsObjectiveComplete(T333B10* t, int id) {
    int i = Objective_Find(StringPool_MakeKey(id));
    int r;
    if (i > -1) r = ((t->bits[i / 32] >> (i & 31)) & 1) != 0;
    else { r = 0; asm { .set reorder } }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333B10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00333B10 */

/* merge_units: begin func_00333B90 */
#pragma push /* merge_units */
/* AgentData_SetObjectiveBit */
typedef struct { void* vt; char pad04[0x18]; int x1C; signed char kind; char pad21[3]; int key; } Msg_333B90;
typedef struct { char pad0[4]; int magic; } Pt2_Tag;
typedef struct { char pad0[0x30]; Pt2_Tag* tgt; } Pt2_Hud;
typedef struct { char pad0[0x84]; unsigned int done[8]; unsigned int seen[8]; } Pt2_Agent;
extern unsigned char g_IsMultiplayer;
extern Pt2_Hud* g_LocalPlayer;
extern char D_005329C0[];
extern void Message_GetScriptTypeKey();
extern void cNetAddObjectiveMsg_dtor();
extern void cNetAddObjectiveMsg_v01();
extern void cNetAddObjectiveMsg_v04();
extern void cNetAddObjectiveMsg_v05();
extern void func_002823E0();
void * const D_004DE810[8] = { (void*)0x0, (void*)0x0, (void*)cNetAddObjectiveMsg_dtor, (void*)cNetAddObjectiveMsg_v01, (void*)func_002823E0, (void*)Message_GetScriptTypeKey, (void*)cNetAddObjectiveMsg_v04, (void*)cNetAddObjectiveMsg_v05 };
extern char D_004DCF10[];
#if 0 /* merge_units */
extern __int128 StringPool_MakeKey(char*);
#endif /* merge_units */
#define StringPool_MakeKey(a0) (StringPool_MakeKey((int)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Objective_Find(__int128);
#endif /* merge_units */
#define Objective_Find(a0) (Objective_Find((a0))) /* merge_units */

extern int Loc_FindKeyThunk(char*);
extern void Event_Construct(Msg_333B90* m, void* type);
extern void Event_Send(Msg_333B90* m, void* target, int x);
extern void cMessage_dtor(Msg_333B90* m, int f);
static inline void Pt2_SetBit(unsigned int* bits, int i) { if (i > -1) bits[i / 32] |= 1 << (i & 0x1F); }

#pragma opt_propagation off
void AgentData_SetObjectiveBit(Pt2_Agent* ag, char* name, int notify) {
    int idx = Objective_Find(StringPool_MakeKey(name));
    Pt2_SetBit(ag->done, idx);
    Pt2_SetBit(ag->seen, idx);
    if (notify && g_IsMultiplayer && g_LocalPlayer && g_LocalPlayer->tgt->magic == 0xBEBAAFDE) {
        Msg_333B90 m;
        Msg_333B90* mp = &m;
        Event_Construct(mp, D_005329C0);
        m.vt = ((char*)D_004DE810);
        mp->key = Loc_FindKeyThunk(name);
        mp->kind = 4;
        mp->x1C = 0x40;
        Event_Send(mp, g_LocalPlayer->tgt, 0);
        m.vt = D_004DCF10;
        cMessage_dtor(mp, 0);
    }
}
#undef StringPool_MakeKey /* merge_units */
#undef Objective_Find /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333B90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00333B90 */
