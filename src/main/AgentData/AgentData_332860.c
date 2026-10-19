/*
 * main/AgentData: range (16 files, 00332860-003330C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00332860 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { signed char a, b, c, d; } E332;
typedef struct { char pad[0xD8]; int count; E332 ent[1]; } H332;
int AgentData_GetBonusFlag(H332* h, int a, int b)
{
    int i;
    for (i = 0; i < h->count; i++) {
        E332* e = &h->ent[i];
        if (e->d == 0 && e->a == a && (b == -1 || e->b == b))
            return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00332860 */

/* merge_units: begin func_003328D0 */
#pragma push /* merge_units */
typedef struct { signed char a, b, c, d; } E3328;
typedef struct { char pad[0xD8]; int count; E3328 ent[(0xB72 - 0xDC) / 4]; char pad2[2]; unsigned char dirty; } H3328;
void AgentData_SetLevelFlag(H3328* h, int a, int b, int c, int v)
{
    int i;
    for (i = 0; i < h->count; i++) {
        E3328* e = &h->ent[i];
        if (e->a == a && e->b == b && e->c == c) {
            if (e->d != (unsigned char)v) {
                e->d = v;
                h->dirty = 1;
            }
            return;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003328D0 */

/* merge_units: begin func_00332950 */
#pragma push /* merge_units */
typedef struct { signed char a, b, c, v; } E32950;
typedef struct { char pad[0xD8]; int count; E32950 e[1]; } T32950;
int AgentData_IsZeusViewed(T32950* self, int a, int b, int c)
{
    int i;
    for (i = 0; i < self->count; i++) {
        E32950* e = &self->e[i];
        if (e->a == a && e->b == b && e->c == c)
            return e->v != 0;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00332950 */

/* merge_units: begin func_003329B0 */
#pragma push /* merge_units */
typedef struct { signed char a, b, c, v; } E329B0;
typedef struct { char pad[0xD8]; int count; E329B0 e[1]; } T329B0;
int AgentData_HasZeus(T329B0* self, int a, int b, int c)
{
    int i;
    for (i = 0; i < self->count; i++) {
        E329B0* e = &self->e[i];
        if (e->a == a && e->b == b && e->c == c)
            return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003329B0 */

/* merge_units: begin func_00332A10 */
#pragma push /* merge_units */
typedef struct { signed char a, b, c, v; } E32A10;
typedef struct { char pad[0xD8]; int count; E32A10 e[(0xB72 - 0xDC) / 4]; char p[2]; unsigned char dirty; } T32A10;
static inline unsigned char Has32A10(T32A10* self, int a, int b, int c)
{
    int i;
    for (i = 0; i < self->count; i++) {
        E32A10* e = &self->e[i];
        if (e->a == a && e->b == b && e->c == c)
            return 1;
    }
    return 0;
}
void AgentData_AddLevelProgress(T32A10* self, int a, int b, int c)
{
    if (!Has32A10(self, a, b - 1, c - 1)) {
        E32A10* e = &self->e[self->count++];
        e->a = a;
        e->b = b - 1;
        e->c = c - 1;
        e->v = 0;
        self->dirty = 1;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00332A10 */

/* merge_units: begin func_00332AC0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E332AC0 { int f0; int id; int p8[3]; int value; };
struct V332AC0 { E332AC0* data; int count; };
struct A332AC0 { char pad[0xB08]; int bits[1]; };
extern "C" {
extern V332AC0 g_UnlockRows;
E332AC0** func_003305C0(V332AC0* v);
void PtrVec_PushBack_1C1080(void* vec, int* v);
}
static inline bool Neq332AC0(E332AC0* a, E332AC0* b) { return !(a == b); }
/* Collects the values of every table entry whose bit is set in the agent's flag array. */
extern "C" void AgentData_GetUnlockedWeapons(A332AC0* a, void* out)
{
    E332AC0* it = *func_003305C0(&g_UnlockRows);
    E332AC0* end = *func_003305C0(&g_UnlockRows) + g_UnlockRows.count;
    for (; Neq332AC0(it, end); it++) {
        int id = it->id;
        if ((a->bits[id / 32] >> (id & 31)) & 1) {
            int v[1];
            v[0] = it->value;
            PtrVec_PushBack_1C1080(out, v);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00332AC0 */

/* merge_units: begin func_00332BB0 */
#pragma push /* merge_units */
typedef struct { int a, b, need; int pad[6]; } E32BB0;
extern int D_00532B74;
extern E32BB0* D_00532B78;
extern int AgentData_TotalPoints(void* self);
int AgentData_IsDossierOpen(void* self, int i)
{
    if (i >= 0 && i < D_00532B74) {
        E32BB0* e = D_00532B78 + i;
        int need = e->need;
        if (need <= AgentData_TotalPoints(self))
            return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00332BB0 */

/* merge_units: begin func_00332C20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "agent_record_has.h"

#pragma opt_strength_reduction off
DEFINE_AGENT_RECORD_HAS(cAgentData_HasCommendation, D_00532A84, D_00532A88, 0xAC0)
#pragma opt_strength_reduction reset
#pragma pop /* merge_units */
/* merge_units: end func_00332C20 */

/* merge_units: begin func_00332CE0 */
#pragma push /* merge_units */
#pragma cplusplus on

#pragma opt_strength_reduction off
DEFINE_AGENT_RECORD_HAS(cAgentData_HasMedal, D_00532A94, D_00532A98, 0xAD0)
#pragma opt_strength_reduction reset
#pragma pop /* merge_units */
/* merge_units: end func_00332CE0 */

/* merge_units: begin func_00332DA0 */
#pragma push /* merge_units */
#pragma cplusplus on

#pragma opt_strength_reduction off
DEFINE_AGENT_RECORD_HAS(cAgentData_HasSpecialRating, D_00532A74, D_00532A78, 0xAB0)
#pragma opt_strength_reduction reset
#pragma pop /* merge_units */
/* merge_units: end func_00332DA0 */

/* merge_units: begin func_00332E60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E32E60 { int id; int a; unsigned char stat; char p9[7]; int need; int p14; };
struct A32E60 { int p0, p4; int stats[1]; };
extern "C" {
extern char D_00532AD0[];
extern int D_00532AD4;
E32E60** func_00330820(void* v);
int Loc_FindKeyThunk(const char* key);
}
static inline bool Neq32E60(E32E60* a, E32E60* b) { return !(a == b); }
extern "C" bool cAgentData_HasRating(A32E60* self, const char* key)
{
    E32E60* first = *func_00330820(D_00532AD0);
    E32E60* last = *func_00330820(D_00532AD0) + D_00532AD4;
    int k = Loc_FindKeyThunk(key);
    for (; Neq32E60(first, last); first++) {
        if (k == first->id)
            return !(self->stats[first->stat] < first->need);
    }
    return false;
}
#pragma pop /* merge_units */
/* merge_units: end func_00332E60 */

/* merge_units: begin func_00332F40 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Bits_2F40 {
    int w[1];
    bool test(int n) const { return (w[n / 32] >> (n & 31)) & 1; }
};
typedef struct { char pad[0xB2C]; Bits_2F40 bits; } AgentD2F40;
#pragma opt_propagation off
extern "C" bool AgentData_HasShownUnlock(AgentD2F40* self, unsigned char idx)
{
    int i = idx;
    bool r;
    if (i > -1) r = self->bits.test(i);
    else r = false;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00332F40 */

/* merge_units: begin func_00332F90 */
#pragma push /* merge_units */
typedef struct { char pad[0xB08]; int bits[1]; } Pt2_Flags;
int AgentData_HasUnlock(Pt2_Flags* p, unsigned char bit) {
    int b = bit;
    if (b > -1) return ((p->bits[b / 32] >> (b & 0x1F)) & 1) != 0;
    else asm { .set reorder } /* barrier: keeps the else block unmerged */
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00332F90 */

/* merge_units: begin func_00332FE0 */
#pragma push /* merge_units */
extern int Awards_FindLevelRow(__int128 key);
typedef struct { char pad[0xB08]; int bits[1]; } AgentD2FE0;
int AgentData_IsLevelDone(AgentD2FE0* self, __int128 key)
{
    int i = Awards_FindLevelRow(key);
    if (i > -1)
        return ((self->bits[i / 32] >> (i & 31)) & 1) != 0;
    asm { .set reorder } /* barrier: keeps retail block layout */ return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00332FE0 */

/* merge_units: begin func_00333050 */
#pragma push /* merge_units */
extern __int128 StringPool_MakeKey(const char* s);
extern int UnlockTable_FindBitByName(__int128 key);
typedef struct { char pad[0xB08]; unsigned int bits[1]; } AgentD3050;
void cAgentData_UnlockWeapon(AgentD3050* self, const char* name)
{
    int i = UnlockTable_FindBitByName(StringPool_MakeKey(name));
    if (i > -1)
        self->bits[i / 32] |= 1 << (i & 31);
}
#pragma pop /* merge_units */
/* merge_units: end func_00333050 */

/* merge_units: begin func_003330C0 */
#pragma push /* merge_units */
typedef struct { char pad[0xB08]; unsigned int bits[1]; } AgentD30C0;
void cAgentData_UnlockLevel(AgentD30C0* self, const char* name)
{
    int i = Awards_FindLevelRow(StringPool_MakeKey(name));
    if (i > -1)
        self->bits[i / 32] |= 1 << (i & 31);
}
#pragma pop /* merge_units */
/* merge_units: end func_003330C0 */
