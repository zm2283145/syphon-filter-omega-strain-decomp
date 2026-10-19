/*
 * main/AgentData: range (4 files, 00333F10-003340B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
void *memset(void *, int, int);

/* merge_units: begin func_00333F10 */
#pragma push /* merge_units */
void Stats_Add(int* stats, unsigned char idx, int n)
{
    if (idx < 31 && n > 0) {
        stats[idx + 2] += n;
        if (idx < 13) {
            stats[idx + 20] += n;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00333F10 */

/* merge_units: begin func_00333F60 */
#pragma push /* merge_units */
typedef struct { char p0[4]; unsigned char b4; } G333F60;
typedef struct { char p0[4]; int f4; char p8[0xB70 - 8]; unsigned char bB70; } A333F60;
extern G333F60 g_MemCard;
extern void AgentData_Reset(A333F60* a);
extern void awards_SetAwardsAndBonuses(A333F60* a, int b, int c);
extern int AgentData_Save(A333F60* a);
static inline int Set333F60(G333F60* g) { return g->b4 != 0; }
/* Resets the agent, re-applies awards and, unless told otherwise, starts the first mission. */
int AgentData_Create(A333F60* a, int x, int skip)
{
    G333F60* g = &g_MemCard;
A333F60* aa = a;
int xx = x;
int ss = skip;
    AgentData_Reset(aa);
    awards_SetAwardsAndBonuses(aa, 0, 1);
    aa->f4 = xx;
    aa->bB70 = 1;
    if (!ss && (Set333F60(g) ^ 1)) return AgentData_Save(aa);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00333F60 */

/* merge_units: begin func_00334000 */
#pragma push /* merge_units */
typedef struct { int d[0x110]; } __attribute__((aligned(16))) Big;
typedef struct { char pad[0x9A4]; Big* buf; unsigned char arr[0x100]; } Obj;
extern void* AgentPacking_Compact(Big* b, int* len);
static inline void QMove(void* d, void* s) {
    int n = 0x44; __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline int Mn(int a, int b) { int r; if (a < b) { r = a; asm { .set reorder } } else r = b; return r; }

void AgentData_StoreAppearance(Obj* o, Big* src)
{
    int len;
    void* data;
    QMove(o->buf, src);
    len = 0;
    data = AgentPacking_Compact(o->buf, &len);
    len = Mn(len, 0x100);
    memset(o->arr, 0, 0x100);
    memcpy(o->arr, data, len);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00334000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00334000 */

/* merge_units: begin func_003340B0 */
#pragma push /* merge_units */
typedef struct { char p0[0x8AC]; char name[0xB73 - 0x8AC]; unsigned char flag; } T340B0;
extern int D_0052FE80;
void AgentData_SetName(T340B0* self, const char* s)
{
    String_Copy(self->name, s);
    if (D_0052FE80) {
        self->flag = 1;
        D_0052FE80 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003340B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003340B0 */
