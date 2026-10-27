/*
 * SFOGame/Source/AgentData: 7 files, 00333790-003337A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00333790 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector element access.
 */

#include "types.h"
#include "AgentData_types.h"

char* std_vector_eAchievementState_opIndex(ByteVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_00333790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00333790 */

/* merge_units: begin func_003337A0 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

#pragma cplusplus on
struct E337A0 { int id; int pad[4]; int val; };
extern "C" {
extern char g_UnlockRows[];
extern int D_00532B14;
E337A0** std_vector_deleter_Record_data(void* v);
}
static inline bool Neq337A0(E337A0* a, E337A0* b) { return !(a == b); }
extern "C" int cAgentData_GetWpnIndex(int id)
{
    if (id > -1) {
        E337A0* first = *std_vector_deleter_Record_data(g_UnlockRows);
        E337A0* last = *std_vector_deleter_Record_data(g_UnlockRows) + D_00532B14;
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
extern int cAgentData_FindRequirement(int, int, int);

void cAgentData_CompleteRequirement(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    v0 = cAgentData_FindRequirement(a0, a1, a2);
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
extern int Libc_Tolower(int c);

int cAgentData_WildcardCompare(void* self, const char* a, const char* b, char wild)
{
    int i = 0;
    int j = 0;
    while (a[i] != 0 && b[j] != 0 && a[i] != wild) {
        if (Libc_Tolower(a[i++]) != Libc_Tolower(b[j++])) return 0;
    }
    i = strlen(a);
    j = strlen(b);
    while (i >= 0 && j >= 0 && a[i] != wild) {
        if (Libc_Tolower(a[i--]) != Libc_Tolower(b[j--])) return 0;
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
E3339E0** std_vector_deleter_Record_data(void* v);
#endif /* merge_units */
#define std_vector_deleter_Record_data(a0) ((E3339E0 * *)std_vector_deleter_Record_data((a0))) /* merge_units */


const char* nGlobalization_GetStringTag(int name);
#if 0 /* merge_units */
int cAgentData_WildcardCompare(A3339E0* self, const char* a, const char* b, char wild);
#endif /* merge_units */
#define cAgentData_WildcardCompare(a0, a1, a2, a3) (cAgentData_WildcardCompare((void *)(a0), (a1), (a2), (a3))) /* merge_units */


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
    E3339E0* first = *std_vector_deleter_Record_data(D_005329F0);
    E3339E0* last = *std_vector_deleter_Record_data(D_005329F0) + D_005329F4;
    for (; Neq3339E0(first, last); first++) {
        if (cAgentData_WildcardCompare(self, pattern, nGlobalization_GetStringTag(first->name), '*')) {
            if (!Done3339E0(self, first->idx)) return 0;
        }
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003339E0(void) {}
#undef std_vector_deleter_Record_data /* merge_units */
#undef cAgentData_WildcardCompare /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003339E0 */

/* merge_units: begin func_00333B10 */
#pragma push /* merge_units */
typedef struct { char pad[0x84]; int bits[1]; } T333B10;
extern __int128 nGlobalization_MakeTag(int id);
extern int GetObjectiveBitIndex__10cAgentDataF1(__int128 key);
int cAgentData_IsObjectiveComplete(T333B10* t, int id) {
    int i = GetObjectiveBitIndex__10cAgentDataF1(nGlobalization_MakeTag(id));
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
/* cAgentData_AddObjective */
typedef struct { void* vt; char pad04[0x18]; int x1C; signed char kind; char pad21[3]; int key; } Msg_333B90;
typedef struct { char pad0[4]; int magic; } Pt2_Tag;
typedef struct { char pad0[0x30]; Pt2_Tag* tgt; } Pt2_Hud;
typedef struct { char pad0[0x84]; unsigned int done[8]; unsigned int seen[8]; } Pt2_Agent;
extern unsigned char g_IsMultiplayer;
extern Pt2_Hud* g_LocalPlayer;
extern char D_005329C0[];
extern void cMessage_getSOBJClassId();
extern void cNetAddObjectiveMsg_dtor();
extern void cNetAddObjectiveMsg_Clone();
extern void cNetAddObjectiveMsg_Pack();
extern void cNetAddObjectiveMsg_GetMsgId();
extern void cNetMsg_Pack();
void * const D_004DE810[8] = { (void*)0x0, (void*)0x0, (void*)cNetAddObjectiveMsg_dtor, (void*)cNetAddObjectiveMsg_Clone, (void*)cNetMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)cNetAddObjectiveMsg_Pack, (void*)cNetAddObjectiveMsg_GetMsgId };
extern char D_004DCF10[];
#if 0 /* merge_units */
extern __int128 nGlobalization_MakeTag(char*);
#endif /* merge_units */
#define nGlobalization_MakeTag(a0) (nGlobalization_MakeTag((int)(a0))) /* merge_units */


#if 0 /* merge_units */
extern int GetObjectiveBitIndex__10cAgentDataF1(__int128);
#endif /* merge_units */
#define GetObjectiveBitIndex__10cAgentDataF1(a0) (GetObjectiveBitIndex__10cAgentDataF1((a0))) /* merge_units */


extern int nGlobalization_GetStringIndex(char*);
extern void cMessage_ctor_cMessageNameR(Msg_333B90* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(Msg_333B90* m, void* target, int x);
extern void cMessage_dtor(Msg_333B90* m, int f);
static inline void Pt2_SetBit(unsigned int* bits, int i) { if (i > -1) bits[i / 32] |= 1 << (i & 0x1F); }

#pragma opt_propagation off
void cAgentData_AddObjective(Pt2_Agent* ag, char* name, int notify) {
    int idx = GetObjectiveBitIndex__10cAgentDataF1(nGlobalization_MakeTag(name));
    Pt2_SetBit(ag->done, idx);
    Pt2_SetBit(ag->seen, idx);
    if (notify && g_IsMultiplayer && g_LocalPlayer && g_LocalPlayer->tgt->magic == 0xBEBAAFDE) {
        Msg_333B90 m;
        Msg_333B90* mp = &m;
        cMessage_ctor_cMessageNameR(mp, D_005329C0);
        m.vt = ((char*)D_004DE810);
        mp->key = nGlobalization_GetStringIndex(name);
        mp->kind = 4;
        mp->x1C = 0x40;
        QueueMessage_cMessageR_cSystemP_int(mp, g_LocalPlayer->tgt, 0);
        m.vt = D_004DCF10;
        cMessage_dtor(mp, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333B90(void) {}
#undef nGlobalization_MakeTag /* merge_units */
#undef GetObjectiveBitIndex__10cAgentDataF1 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00333B90 */
