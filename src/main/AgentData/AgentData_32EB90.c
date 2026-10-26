/*
 * main/AgentData: 5 files, 0032EB90-0032EDF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032EB90 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char data[0x30]; } Rank;
extern char g_RankRows[];
extern int Loc_FindKeyThunk(const char* s);           /* string hash */
extern int Awards_ResolveUnlock(int hash);
extern int cArray_tRankInfo_Size(void* registry);
extern void* Awards_FormatRankTitle(Rank* r, int a, int b, int req, int index, int d);
extern void cArray_tRankInfo_PushBackActual(void* registry, void* item);

/* Script native: registers a rank (args[0], args[1], requirement named args[2], args[3]); returns 0. */
int Script_cAgentData__RegisterRank_3(ScriptArg* args)
{
    Rank r;
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    int a3;
    int req;
    int a0;
    int a1;
    int a2;
    p3[0] = args[3].i;
    a3 = *(int*)p3;
    p2[0] = args[2].i;
    a2 = *(int*)p2;
    p1[0] = args[1].i;
    a1 = *(int*)p1;
    p0[0] = args[0].i;
    a0 = *(int*)p0;
    req = Awards_ResolveUnlock(Loc_FindKeyThunk((const char*)a2));
    cArray_tRankInfo_PushBackActual(g_RankRows, Awards_FormatRankTitle(&r, a0, a1, req, cArray_tRankInfo_Size(g_RankRows), a3));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032EB90 */

/* merge_units: begin func_0032EC50 */
#pragma push /* merge_units */
typedef struct RankArgs {
    int a0;
    int a1;
    int weapon;
} RankArgs;

/* Temporary rank record built on the stack. */
typedef struct RankRec {
    char data[0x20];
} RankRec;
#if 0 /* merge_units */
extern int Loc_FindKeyThunk(int handle);
#endif /* merge_units */
#define Loc_FindKeyThunk(a0) (Loc_FindKeyThunk((const char *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Awards_ResolveUnlock(int id);
#endif /* merge_units */
#define Awards_ResolveUnlock(a0) (Awards_ResolveUnlock((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Awards_FormatRankTitle(RankRec* rec, int a0, int a1, int id, int index, int flags);
#endif /* merge_units */
#define Awards_FormatRankTitle(a0, a1, a2, a3, a4, a5) ((int)Awards_FormatRankTitle((Rank *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void cArray_tRankInfo_PushBackActual(void* registry, int rec);
#endif /* merge_units */
#define cArray_tRankInfo_PushBackActual(a0, a1) (cArray_tRankInfo_PushBackActual((a0), (void *)(a1))) /* merge_units */


/* Script native: cAgentData._RegisterRank(a0, a1, weapon). */
int Script_cAgentData__RegisterRank_2(RankArgs* args) {
    RankRec rec;
    int id, v0, v1, v2;
    volatile int w2, w1, w0;
    w2 = args->weapon;
    v2 = w2;
    w1 = args->a1;
    v1 = w1;
    w0 = args->a0;
    v0 = w0;
    id = Awards_ResolveUnlock(Loc_FindKeyThunk(v2));
    cArray_tRankInfo_PushBackActual(g_RankRows, Awards_FormatRankTitle(&rec, v0, v1, id, cArray_tRankInfo_Size(g_RankRows), 0));
    return 0;
}
#undef Loc_FindKeyThunk /* merge_units */
#undef Awards_ResolveUnlock /* merge_units */
#undef Awards_FormatRankTitle /* merge_units */
#undef cArray_tRankInfo_PushBackActual /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032EC50 */

/* merge_units: begin func_0032ECF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x28]; } Rank_0032ECF0;
#if 0 /* merge_units */
extern void* Loc_FindKeyThunk(int);
#endif /* merge_units */
#define Loc_FindKeyThunk(a0) ((void *)Loc_FindKeyThunk((const char *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Awards_ResolveUnlock(void*);
#endif /* merge_units */
#define Awards_ResolveUnlock(a0) (Awards_ResolveUnlock((int)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cArray_tRankInfo_Size(void*);
#endif /* merge_units */
#define cArray_tRankInfo_Size(a0) (cArray_tRankInfo_Size((a0))) /* merge_units */

#if 0 /* merge_units */
extern Rank_0032ECF0* Awards_FormatRankTitle(Rank_0032ECF0* r, int name, int score, int a, int b, int c);
#endif /* merge_units */
#define Awards_FormatRankTitle(a0, a1, a2, a3, a4, a5) ((Rank_0032ECF0 *)Awards_FormatRankTitle((Rank *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void cArray_tRankInfo_PushBackActual(void* list, Rank_0032ECF0* r);
#endif /* merge_units */
#define cArray_tRankInfo_PushBackActual(a0, a1) (cArray_tRankInfo_PushBackActual((a0), (void *)(a1))) /* merge_units */

/* Script native: registers rank args[0] with threshold args[1]; returns 0. */
int Script_cAgentData__RegisterRank(ScriptArg* args)
{
    int score[1];
    int name[1];
    int agent;
    int n;
    int s;
    Rank_0032ECF0 rank;
    score[0] = args[1].i;
    s = *(volatile int*)score;
    name[0] = args[0].i;
    n = *(volatile int*)name;
    agent = Awards_ResolveUnlock(Loc_FindKeyThunk(0));
    cArray_tRankInfo_PushBackActual(g_RankRows, Awards_FormatRankTitle(&rank, n, s, agent, cArray_tRankInfo_Size(g_RankRows), 0));
    return 0;
}
#undef Loc_FindKeyThunk /* merge_units */
#undef Awards_ResolveUnlock /* merge_units */
#undef cArray_tRankInfo_Size /* merge_units */
#undef Awards_FormatRankTitle /* merge_units */
#undef cArray_tRankInfo_PushBackActual /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032ECF0 */

/* merge_units: begin func_0032ED90 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg_0032ED90;
typedef struct { char data[0x24]; } BonusReq;

extern char D_00532AA0[];
extern void* AwardRow_Construct(BonusReq* req, int level, int a, int b, int c, int d);
extern void cArray_Record_PushBackActual(void* list, void* item);

/* Script native: registers a bonus level requirement with the agent data. */
int Script_cAgentData__RegisterBonusLevel(ScriptArg_0032ED90* args)
{
    BonusReq req;
    int c[1];
    int b[1];
    int level[1];
    c[0] = args[2].i;
    b[0] = args[1].i;
    level[0] = args[0].i;
    cArray_Record_PushBackActual(D_00532AA0, AwardRow_Construct(&req, *(int*)level, 0, *(int*)b, *(int*)c, 0));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032ED90 */

/* merge_units: begin func_0032EDF0 */
#pragma push /* merge_units */
typedef struct LevelReq {
    char b[0x18];
} LevelReq;

typedef struct LevelKey {
    char b[8];
} LevelKey;

extern int D_004926E0;
extern int D_00532AF0;
extern int D_00532B90;
extern void* ObjectiveRow_Construct(LevelReq*, int, int, int);
#if 0 /* merge_units */
extern void cArray_Record_PushBackActual(void*, void*);
#endif /* merge_units */
#define cArray_Record_PushBackActual(a0, a1) (cArray_Record_PushBackActual((a0), (a1))) /* merge_units */

extern void* cAgentData_tParTimes_ctor(LevelKey*, int, int);
extern void cArray_tParTimes_PushBackActual(void*, void*);

/* Script: cAgentData::RegisterLevel(a, b, c, d) - registers a level and its key. */
int Script_cAgentData__RegisterLevel_2(ScriptArg* args) {
    LevelReq req;
    LevelKey key;
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    int index;
    int bv;
    int cv;
    d[0] = args[3].i;
    index = D_004926E0;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    D_004926E0 = index + 1;
    cv = *(int*)c;
    bv = *(int*)b;
    cArray_Record_PushBackActual(&D_00532AF0, ObjectiveRow_Construct(&req, *(int*)a, *(int*)d, index));
    cArray_tParTimes_PushBackActual(&D_00532B90, cAgentData_tParTimes_ctor(&key, bv, cv));
    return 0;
}
#undef cArray_Record_PushBackActual /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032EDF0 */
