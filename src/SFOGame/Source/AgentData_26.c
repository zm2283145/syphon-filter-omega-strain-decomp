/*
 * SFOGame/Source/AgentData: 8 files, 00333D60-00334100
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00333D60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct Msg {
    void* vtable;
    char base[0x20];
    int id;                 /* 0x24 */
    char pad[8];
} Msg;
extern char D_005329C0[];
extern char D_004DE810[];
extern char D_004DCF10[];
extern char g_Game[];
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
extern void cNetMsg_GetInt(int* out);
extern void* cGameSystem_GetAgentData(void* list, int index);
extern int nGlobalization_GetStringTag(int id);
extern void cAgentData_AddObjective(void* agent, int bit, int value);
extern void cMessage_dtor(Msg* msg, int flags);
/* Network handler: reads an objective id and clears that bit on the selected agent. */
void func_00333D60(void)
{
    Msg msg;
    void* agent;
    cMessage_ctor_cMessageNameR(&msg, D_005329C0);
    msg.vtable = D_004DE810;
    cNetMsg_GetInt(&msg.id);
    agent = cGameSystem_GetAgentData(g_Game, -1);
    cAgentData_AddObjective(agent, nGlobalization_GetStringTag(msg.id), 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_00333D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00333D60 */

/* merge_units: begin func_00333DF0 */
#pragma push /* merge_units */
#include "AgentData_types.h"
void cAgentData_ResetStats(cAgentData* agent)
{
    { int i; for (i = 0; i < 13; i++) agent->stats[i] -= agent->stats[i + 18]; }
    { int i; for (i = 18; i < 31; i++) agent->stats[i] = 0; }
    { int i; for (i = 0; i < 8; i++) agent->missionBits[i] = 0; }
}
static inline void merge_flush_func_00333DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00333DF0 */

/* merge_units: begin func_00333EE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData statistics.
 */


/* Returns statistic `stat`, or 0 when out of range. */
int cAgentData_GetStat(cAgentData* agent, unsigned char stat) {
    if (stat < AGENT_STAT_COUNT) {
        return agent->stats[stat];
    }
    return 0;
}
static inline void merge_flush_func_00333EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00333EE0 */

/* merge_units: begin func_00333F10 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
void *memset(void *, int, int);

void cAgentData_AddScore(int* stats, unsigned char idx, int n)
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
extern void cAgentData_Reset(A333F60* a);
extern void cAgentData_SetBonusBits(A333F60* a, int b, int c);
extern int AgentData_Save(A333F60* a);
static inline int Set333F60(G333F60* g) { return g->b4 != 0; }
/* Resets the agent, re-applies awards and, unless told otherwise, starts the first mission. */
int cAgentData_Create(A333F60* a, int x, int skip)
{
    G333F60* g = &g_MemCard;
A333F60* aa = a;
int xx = x;
int ss = skip;
    cAgentData_Reset(aa);
    cAgentData_SetBonusBits(aa, 0, 1);
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
extern void* SKL_CompressSKL(Big* b, int* len);
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

void cAgentData_SetSkl(Obj* o, Big* src)
{
    int len;
    void* data;
    QMove(o->buf, src);
    len = 0;
    data = SKL_CompressSKL(o->buf, &len);
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
    Libc_Strcpy(self->name, s);
    if (D_0052FE80) {
        self->flag = 1;
        D_0052FE80 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003340B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003340B0 */

/* merge_units: begin func_00334100 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Constant getter.
 */


int cAgentData_GetNumSavedBytes(void) {
    return 16000;
}
static inline void merge_flush_func_00334100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00334100 */
