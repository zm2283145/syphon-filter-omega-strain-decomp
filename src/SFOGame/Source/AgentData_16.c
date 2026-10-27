/*
 * SFOGame/Source/AgentData: 10 files, 0032FCA0-003301E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032FCA0 */
#pragma push /* merge_units */
#include "types.h"

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

/* merge_units: begin func_0032FD30 */
#pragma push /* merge_units */
#include "AgentData_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (clearance points).
 */


extern int cAgentData_GetClearancePoints(cAgentData* agent);

/* Returns the agent's total clearance points; volatile mirrors the stack temporary. */
int Script_cAgentData_GetClearancePoints(AgentScriptArg* args) {
    volatile int points = cAgentData_GetClearancePoints(args[0].p);
    return points;
}

void cAgentData_SOBJ_init(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FD30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FD30 */

/* merge_units: begin func_0032FD70 */
#pragma push /* merge_units */
typedef struct { int key; int a; char b; int c; int d; int e; } Medal;
extern int nGlobalization_GetStringIndex(const char* name);

/* Medal constructor: resolves the name key and stores the fields; id is 10000 + index. */
Medal* cAgentData_RatingRecord_ctor_charP_int_eScoreTypes_int_etc(Medal* self, const char* name, int a, char b, int c, int d, unsigned char index)
{
    self->key = nGlobalization_GetStringIndex(name);
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

/* merge_units: begin func_0032FE00 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma cplusplus on
struct E_32FE00 { int id; int pad[4]; int val; };
struct O_32FE00 { int key; int id; char flag; int a; int b; int val; };
extern "C" {
extern char g_UnlockRows[];
E_32FE00* std_vector_imp_Record_begin(void* t);
E_32FE00* std_vector_imp_Record_end(void* t);
void std_vector_Record_pointer2iterator(E_32FE00** out, void* t, E_32FE00** raw);
#if 0 /* merge_units */
int nGlobalization_GetStringIndex(const char* key);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((a0))) /* merge_units */

int nGlobalization_GetString_charP(int id);
}
static inline bool Neq_32FE00(E_32FE00* a, E_32FE00* b) { return !(a == b); }
static inline int Find_32FE00(const char* key)
{
    int k = nGlobalization_GetStringIndex(key);
    if (k > -1) {
        E_32FE00* b;
        E_32FE00* e;
        E_32FE00* t1;
        E_32FE00* t2;
        E_32FE00* first;
        t1 = std_vector_imp_Record_begin(g_UnlockRows);
        std_vector_Record_pointer2iterator(&b, g_UnlockRows, &t1);
        first = b;
        t2 = std_vector_imp_Record_end(g_UnlockRows);
        std_vector_Record_pointer2iterator(&e, g_UnlockRows, &t2);
        for (E_32FE00* last = e; Neq_32FE00(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32FE00* cAgentData_RatingRecord_ctor_charP_int_eScoreTypes_int_etc_2(O_32FE00* self, const char* name, int id, char flag, int a, int b, const char* key)
{
    self->key = nGlobalization_GetStringIndex(name);
    self->id = id;
    self->flag = flag;
    self->a = a;
    self->b = b;
    self->val = key ? Find_32FE00(key) : -1;
    return self;
}
#undef nGlobalization_GetStringIndex /* merge_units */
static inline void merge_flush_func_0032FE00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FE00 */

/* merge_units: begin func_0032FF50 */
#pragma push /* merge_units */
typedef struct { int name; int unk4; int desc; int value; int id; int extra; } Rec0032FF50;
#if 0 /* merge_units */
extern int nGlobalization_GetStringIndex(int key);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((const char *)(a0))) /* merge_units */

/* Fill a rating record. */
Rec0032FF50* cAgentData_Record_ctor_charP_int_charP_int_etc(Rec0032FF50* rec, int nameKey, int extra, int descKey, int value, unsigned char id)
{
    rec->name = nGlobalization_GetStringIndex(nameKey);
    rec->extra = extra;
    rec->desc = nGlobalization_GetStringIndex(descKey);
    rec->value = value;
    rec->id = id + 10000;
    return rec;
}
#undef nGlobalization_GetStringIndex /* merge_units */
static inline void merge_flush_func_0032FF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FF50 */

/* merge_units: begin func_0032FFD0 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma cplusplus on
struct E_32FFD0 { int id; int pad[4]; int val; };
struct O_32FFD0 { int key; int p4; int key2; int c; int val; int x; };
extern "C" {
#if 0 /* merge_units */
E_32FFD0* std_vector_imp_Record_begin(void* t);
#endif /* merge_units */
#define std_vector_imp_Record_begin(a0) ((E_32FFD0 *)std_vector_imp_Record_begin((a0))) /* merge_units */

#if 0 /* merge_units */
E_32FFD0* std_vector_imp_Record_end(void* t);
#endif /* merge_units */
#define std_vector_imp_Record_end(a0) ((E_32FFD0 *)std_vector_imp_Record_end((a0))) /* merge_units */

#if 0 /* merge_units */
void std_vector_Record_pointer2iterator(E_32FFD0** out, void* t, E_32FFD0** raw);
#endif /* merge_units */
#define std_vector_Record_pointer2iterator(a0, a1, a2) (std_vector_Record_pointer2iterator((E_32FE00 * *)(a0), (a1), (E_32FE00 * *)(a2))) /* merge_units */

#if 0 /* merge_units */
int nGlobalization_GetStringIndex(const char* key);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((a0))) /* merge_units */

}
static inline bool Neq_32FFD0(E_32FFD0* a, E_32FFD0* b) { return !(a == b); }
static inline int Find_32FFD0(const char* key)
{
    int k = nGlobalization_GetStringIndex(key);
    if (k > -1) {
        E_32FFD0* b;
        E_32FFD0* e;
        E_32FFD0* t1;
        E_32FFD0* t2;
        E_32FFD0* first;
        t1 = std_vector_imp_Record_begin(g_UnlockRows);
        std_vector_Record_pointer2iterator(&b, g_UnlockRows, &t1);
        first = b;
        t2 = std_vector_imp_Record_end(g_UnlockRows);
        std_vector_Record_pointer2iterator(&e, g_UnlockRows, &t2);
        for (E_32FFD0* last = e; Neq_32FFD0(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32FFD0* cAgentData_Record_ctor_charP_int_charP_int_etc_2(O_32FFD0* self, const char* name, int x, const char* name2, int c, const char* key)
{
    self->key = nGlobalization_GetStringIndex(name);
    self->x = x;
    self->key2 = nGlobalization_GetStringIndex(name2);
    self->c = c;
    self->val = key ? Find_32FFD0(key) : -1;
    return self;
}
#undef std_vector_imp_Record_begin /* merge_units */
#undef std_vector_imp_Record_end /* merge_units */
#undef std_vector_Record_pointer2iterator /* merge_units */
#undef nGlobalization_GetStringIndex /* merge_units */
static inline void merge_flush_func_0032FFD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FFD0 */

/* merge_units: begin func_00330110 */
#pragma push /* merge_units */
typedef struct { void* buffer; int unk4; int index; int unkC; char pad[4]; int unk14; } Obj330;

extern void* g_WeaponDatabase;
extern char* cWeaponDB_GetEntry(void* p);
#if 0 /* merge_units */
extern void* nGlobalization_GetStringIndex(char* p);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) ((void *)nGlobalization_GetStringIndex((const char *)(a0))) /* merge_units */


/* Constructor: allocates the buffer and initializes the fields; returns self. */
Obj330* cAgentData_Record_ctor_int_int(Obj330* self, int a, int b)
{
    self->buffer = nGlobalization_GetStringIndex(cWeaponDB_GetEntry(g_WeaponDatabase) + 0x80);
    self->unk14 = a;
    self->unk4 = b;
    self->index = -1;
    self->unkC = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330110(void) {}
#undef nGlobalization_GetStringIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00330110 */

/* merge_units: begin func_00330180 */
#pragma push /* merge_units */
typedef struct { int text; int unk4; int unk8; int unkC; int unk10; int unk14; } ObjectiveRow_00330180;
#if 0 /* merge_units */
extern int nGlobalization_GetStringIndex(const char* key);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((a0))) /* merge_units */



/* Initialises an objective row: looks up the text key and stores the parameters. */
ObjectiveRow_00330180* cAgentData_Record_ctor_charP_int_int(ObjectiveRow_00330180* row, const char* key, int a, int b)
{
    row->text = nGlobalization_GetStringIndex(key);
    row->unk14 = a;
    row->unk4 = b;
    row->unk8 = -1;
    row->unkC = 0;
    return row;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330180(void) {}
#undef nGlobalization_GetStringIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00330180 */

/* merge_units: begin func_003301E0 */
#pragma push /* merge_units */
typedef struct { int pad[4]; int level; } E301E0;
typedef struct { int a; int count; } T301E0;
extern int D_00532B34;
extern E301E0* D_00532B38;
extern void std_vector_charPtr_push_back_charPR_2(T301E0* self, E301E0** e);
#pragma opt_strength_reduction off
void cAgentData_GetLockedParts_cArrayP_int(T301E0* self, int level)
{
    int i;
    self->count = 0;
    for (i = 0; i < D_00532B34; i++) {
        E301E0* e[1];
        E301E0* p = &D_00532B38[i];
        e[0] = p;
        if (level < p->level)
            std_vector_charPtr_push_back_charPR_2(self, e);
    }
}
#pragma opt_strength_reduction reset
static inline void merge_flush_func_003301E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003301E0 */
