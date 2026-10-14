/*
 * main/AgentData: range (9 files, 003308E0-003314F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
int strcmp(const void *, const void *);

/* merge_units: begin func_003308E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E308E0 { int id; int val; int pad[4]; };
extern "C" {
extern char D_00532B10[];
int func_0032E3F0(void* t);
int func_0032E3C0(void* t);
void func_0032E3E0(E308E0** out, void* t, int* raw);
int Loc_FindKeyThunk(__int128* key);
}
static inline bool Neq308E0(E308E0* a, E308E0* b) { return !(a == b); }
extern "C" int UnlockTable_FindBitByName(__int128 key)
{
    E308E0* b;
    E308E0* e;
    int t1;
    int t2;
    E308E0* first;
    E308E0* last;
    int k;
    int r;
    t1 = func_0032E3F0(D_00532B10);
    func_0032E3E0(&b, D_00532B10, &t1);
    first = b;
    t2 = func_0032E3C0(D_00532B10);
    func_0032E3E0(&e, D_00532B10, &t2);
    last = e;
    k = Loc_FindKeyThunk(&key);
    for (; Neq308E0(first, last); first++) {
        if (k == first->id) {
            r = first->val;
            goto found;
        }
    }
    r = -1;
found:
    if (r < 0)
        r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003308E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003308E0 */

/* merge_units: begin func_003309C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E309C0 { int id; int val; int pad[4]; };
extern "C" {
extern char D_00532AF0[];
#if 0 /* merge_units */
void func_0032E3E0(E309C0** out, void* t, int* raw);
#endif /* merge_units */
#define func_0032E3E0(a0, a1, a2) (func_0032E3E0((E308E0 * *)(a0), (a1), (a2))) /* merge_units */

}
static inline bool Neq309C0(E309C0* a, E309C0* b) { return !(a == b); }
extern "C" int func_003309C0(__int128 key)
{
    E309C0* b;
    E309C0* e;
    int t1;
    int t2;
    E309C0* first;
    E309C0* last;
    int k;
    int r;
    t1 = func_0032E3F0(D_00532AF0);
    func_0032E3E0(&b, D_00532AF0, &t1);
    first = b;
    t2 = func_0032E3C0(D_00532AF0);
    func_0032E3E0(&e, D_00532AF0, &t2);
    last = e;
    k = Loc_FindKeyThunk(&key);
    for (; Neq309C0(first, last); first++) {
        if (k == first->id) {
            r = first->val;
            goto found;
        }
    }
    r = -1;
found:
    if (r < 0)
        r = 0;
    return r;
}
#undef func_0032E3E0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003309C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003309C0 */

/* merge_units: begin func_00330AA0 */
#pragma push /* merge_units */
typedef struct { int key; int value; char pad8[0x10]; } Row330;
typedef struct { Row330* p; } It330;
extern char D_005329F0[];
#if 0 /* merge_units */
extern Row330* func_0032E3F0(void* v);
#endif /* merge_units */
#define func_0032E3F0(a0) ((Row330 *)func_0032E3F0((a0))) /* merge_units */

#if 0 /* merge_units */
extern Row330* func_0032E3C0(void* v);
#endif /* merge_units */
#define func_0032E3C0(a0) ((Row330 *)func_0032E3C0((a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_0032E3E0(It330* out, void* self, It330* src);
#endif /* merge_units */
#define func_0032E3E0(a0, a1, a2) (func_0032E3E0((void *)(a0), (a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int Loc_FindKeyThunk(__int128* name);
#endif /* merge_units */
#define Loc_FindKeyThunk(a0) (Loc_FindKeyThunk((a0))) /* merge_units */

#pragma bool off
static inline int Ne330(Row330* a, Row330* b) { return (a == b) ^ 1; }
static inline int Find330(__int128* name)
{
    It330 itB;
    It330 itE;
    It330 b;
    It330 e;
    Row330* p;
    Row330* end;
    int key;
    b.p = func_0032E3F0(D_005329F0);
    func_0032E3E0(&itB, D_005329F0, &b);
    p = itB.p;
    e.p = func_0032E3C0(D_005329F0);
    func_0032E3E0(&itE, D_005329F0, &e);
    end = itE.p;
    key = Loc_FindKeyThunk(name);
    for (; Ne330(p, end); p++) {
        if (key == p->key) return p->value;
    }
    return -1;
}
int Objective_Find(__int128 name)
{
    int r = Find330(&name);
    if (r < 0) r = 0;
    return r;
}
#undef func_0032E3F0 /* merge_units */
#undef func_0032E3C0 /* merge_units */
#undef func_0032E3E0 /* merge_units */
#undef Loc_FindKeyThunk /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330AA0 */

/* merge_units: begin func_00330B80 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct LookupE6 {
    void* name;
    int pad[4];
    int value;
} LookupE6;

extern int D_00532AF4;
extern LookupE6* D_00532AF8;
extern void* Loc_GetStoredKey(void* name);
extern int String_CompareNoCase(void* a, void* b);

static inline LookupE6* EntryE6(int i) { return &D_00532AF8[i]; }

/* Finds the table entry whose name matches, returning its value (default 0x16). */
int Objective_GetLevelMissionNumber(void* name)
{
    int count = D_00532AF4;
    int i;
    for (i = 0; i < count; i++) {
        if (String_CompareNoCase(Loc_GetStoredKey(EntryE6(i)->name), name) == 0) {
            return EntryE6(i)->value;
        }
    }
    return 0x16;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330B80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330B80 */

/* merge_units: begin func_00330C30 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct Lookup30C30 { void* name; int pad[5]; } Lookup30C30;
typedef struct Pair30C30 { int a; int b; } Pair30C30;
#if 0 /* merge_units */
extern Lookup30C30* D_00532AF8;
#endif /* merge_units */
#define D_00532AF8 (*(Lookup30C30 **)&D_00532AF8) /* merge_units */

extern Pair30C30* D_00532B98;

static inline Lookup30C30* Entry30C30(int i) { return &D_00532AF8[i]; }

/* Finds the table entry whose name matches and returns one of its two paired values. */
int func_00330C30(void* name, int second)
{
    int count = D_00532AF4;
    int i;
    for (i = 0; i < count; i++) {
        if (String_CompareNoCase(Loc_GetStoredKey(Entry30C30(i)->name), name) == 0) {
            return second ? ((int*)D_00532B98)[i * 2 + 1] : ((int*)D_00532B98)[i * 2];
        }
    }
    return 0;
}
#undef D_00532AF8 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330C30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330C30 */

/* merge_units: begin func_00330D10 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct DosDef {
    const char* name;
    int unk04;
    int index;
    char pad0C[0x18];
} DosDef;

typedef struct DosDefVec {
    int unk00;
    int count;
    DosDef* data;
} DosDefVec;

typedef struct DosEntry {
    int agent;
    int num;
    int dossier;
    int unk0C;
    unsigned char flag;
    char pad11[0xF];
    int key;
} DosEntry;

typedef struct DosEntryVec {
    int unk00;
    int count;
    DosEntry* data;
} DosEntryVec;

extern DosDefVec D_00532B50;
extern DosEntryVec D_00532B70;
extern char D_004B99A8[];
#if 0 /* merge_units */
extern int Loc_FindKeyThunk(const char* key);
#endif /* merge_units */
#define Loc_FindKeyThunk(a0) (Loc_FindKeyThunk((void *)(a0))) /* merge_units */

extern int func_00338B60(DosEntryVec* v, DosEntry* pos, int count, DosEntry* value);

static inline DosDef* At(DosDefVec* v, int i) { return &v->data[i]; }
void Global_cAgentData__RegisterDossier(int agent, const char* name)
{
    int found = 0;
    int i;
    DosEntry e;
    char buf[16];
    for (i = 0; i < D_00532B50.count; i++) {
        if (strcmp(At(&D_00532B50, i)->name, name) == 0) {
            found = At(&D_00532B50, i)->index;
            break;
        }
    }
    e.agent = agent;
    e.dossier = found;
    e.unk0C = -1;
    e.num = 0;
    e.flag = 0;
    sprintf(buf, D_004B99A8, e.num + 1);
    e.key = Loc_FindKeyThunk(buf);
    func_00338B60(&D_00532B70, &D_00532B70.data[D_00532B70.count], 1, &e);
}
#undef Loc_FindKeyThunk /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330D10 */

/* merge_units: begin func_00330E40 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0;
static inline short R16_330E40(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_330E40(void) { unsigned short lo = R16_330E40(); return lo + ((unsigned short)R16_330E40() << 16); }
typedef struct { char p0[8]; int f[31]; char p84[0xB70 - 0x84]; unsigned char done; } T330E40;
void func_00330E40(T330E40* t) {
    int i;
    i = 14; do { t->f[i] = R32_330E40(); i++; } while (i < 31);
    t->done = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330E40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330E40 */

/* merge_units: begin func_00330F00 */
#pragma push /* merge_units */
static inline void W16_00330F00(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00330F00(int v) { W16_00330F00((unsigned short)v); W16_00330F00(v >> 16); }
typedef struct { char pad[8]; int v[31]; } S_00330F00;
void func_00330F00(S_00330F00* p) {
    int i;
    for (i = 14; i < 31; i++) {
        W32_00330F00(p->v[i]);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330F00 */

/* merge_units: begin func_003314F0 */
#pragma push /* merge_units */
extern void AgentData_Reset(void);
extern int func_00334780(void);
extern void func_00281E90(char* s, int n);
extern void awards_SetAwardsAndBonuses(void* p, int a, int b);
extern void func_00335D50(void* p, int a);
static inline short R16_003314F0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_003314F0(void) { unsigned short lo = R16_003314F0(); return lo + ((unsigned short)R16_003314F0() << 16); }
static inline float RF_003314F0(void) { int i = R32_003314F0(); return *(float*)&i; }
typedef struct { int v; char pad[0x1C]; } E_003314F0;
typedef struct {
    char pad0[8]; int v[31]; int w[17]; int count; E_003314F0* e; int pad_d0; float f;
    char padd8[0x8AC - 0xD8]; char s0[16]; char s1[16]; char s2[16];
    char pad8dc[0xB70 - 0x8DC]; unsigned char done; char padb71[3]; unsigned char flag;
} S_003314F0;
#pragma push
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
void func_003314F0(S_003314F0* p, int awards) {
    int i; int j; int k; int n; S_003314F0* q; S_003314F0* r;
    AgentData_Reset();
    p->s0[0] = 0;
    p->s1[0] = 0;
    p->s2[0] = 0;
    n = func_00334780();
    i = 0; if (i < n) { q = p; do { q->w[0] = R32_003314F0(); q = (S_003314F0*)((int*)q + 1); } while (++i < n); }
    for (j = 0, r = p; j < 31; j++) { r->v[0] = R32_003314F0(); r = (S_003314F0*)((int*)r + 1); }
    for (k = 0; k < p->count; k++) { E_003314F0* e = &p->e[k]; e->v = R32_003314F0(); }
    func_00281E90(p->s0, 0x10);
    p->f = RF_003314F0();
    {
        char c = *D_005061D0++;
        p->flag = c != 0;
    }
    if (awards) awards_SetAwardsAndBonuses(p, 0, 0);
    else func_00335D50(p, 0);
    p->done = 1;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003314F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003314F0 */
