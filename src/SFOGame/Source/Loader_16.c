/*
 * SFOGame/Source/Loader: 3 files, 001C1E40-001C1E70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C1E40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern char D_0048B2F8[];   /* game data root directory name */
extern int g_VisionFxMan;
extern int nSfxLoader_LoadEffects(char* root, int a1);
extern int cVisionFxMan_UpdateTxtrIds(int a0);

/* Call nSfxLoader_LoadEffects with the game data root and a2, then cVisionFxMan_UpdateTxtrIds on g_VisionFxMan. */
int cLoader_LoadEffects(int a0, int a1, int a2) {
    nSfxLoader_LoadEffects(D_0048B2F8, a2);
    return cVisionFxMan_UpdateTxtrIds(g_VisionFxMan);
}
static inline void merge_flush_func_001C1E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C1E40 */

/* merge_units: begin func_001C1E70 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "pop_reader.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "fileman_entry.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "Loader_types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

#pragma cplusplus on

struct NpcObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetActive(int on);
    char pad04[0x8];
    unsigned int flagsC;
    char pad10[0xC];
    void* reg;
    char pad20[0x38];
    int actorId;
    char pad5C[0x4];
    char sub60[0x40];
    char appearance[0x10];
};
struct NpcColor { char data[0x440]; };
struct BodyTbl { char pad[0xF8]; int tbl[1][4]; };
struct NetState { char pad[0x250]; unsigned char b250; };

extern "C" {
extern char D_0049EE88[];
extern char D_0049F050[], D_0049F070[], D_0049F090[], D_0049F0A8[], D_0049F0B8[];
extern char D_0057124C[], D_005711B0[];
extern char g_Game[];
extern NetState* D_004FFC04;
extern unsigned char D_004FFBB2;
extern signed char D_00493A60;
extern NpcColor D_0055D510[];
extern int D_0055DE94;
extern BodyTbl g_AgentPartCache;
extern void* g_ActorList;
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMachine_ShowLoadingScreen(void* a, char* name, int x);
void* GetMachine(void);
int cHogList_Open(void* a, char* name, int b, int c);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(void* hog, char* name, int h, int b);
void cMan_LoadIRTextures(void* hog);
void cMan_ManInit(void);
NpcObj* cHuman_ctor_cPopulationR_eCharacterType_SKLP_cGeneratorParamsP(void* p, PopReader* r, int kind, NpcColor* color, int x);
void cGameSystem_SetPlayer(void* w, int id);
void nGobjManager_SetPlayer(NpcObj* o);
int SKL_FindSex(void* a);
void cMan_AddDisguise(void* a, int b);
void cBaseObjList_Add(void* reg, NpcObj* o);
void Monster_MonsterPartMemory(void* a);
}

static inline void SkipStr(PopReader* r)
{
    while (*r->cur++)
        ;
}

static inline void Align(PopReader* r)
{
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
}

/* new cNPC(r, 1, &colors[D_00493A60]): the color index is read after the allocation */
static inline NpcObj* NewPlayer(PopReader* r)
{
    NpcObj* p;
    {
        AllocGuard g;
        p = (NpcObj*)cMemMan_Allocate(0, 0x35A0, D_0049EE88, 0x32A);
    }
    if (p)
        p = cHuman_ctor_cPopulationR_eCharacterType_SKLP_cGeneratorParamsP(p, r, 1, &D_0055D510[D_00493A60], 0);
    return p;
}

extern "C" void cLoader_LoadSKMs(void* unused, PopReader* r, void* arc)
{
    char thermal[128];
    char name[128];
    FileManEntry e;
    cFileMan_ctor_void(&e);
    cMachine_ShowLoadingScreen(GetMachine(), D_0049F050, 0);
    sprintf(thermal, D_0049F070, D_0048B2F8);
    sprintf(name, D_0049F090, D_0048B2F8);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(D_0057124C, D_0049F0A8, cHogList_Open(arc, name, 1, 0), 1);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(D_005711B0, D_0049F0B8, cHogList_Open(arc, thermal, 1, 0), 1);
    cMan_LoadIRTextures(D_005711B0);
    cMan_ManInit();
    if (!(unsigned char)cPopulation_SeekBlock(r, 0x3A43504E)) {
        cFileMan_dtor(&e, -1);
        return;
    }
    {
        int n;
        NpcObj* p;
        int i;
        n = *(int*)r->cur;
        r->cur += 4;
        for (i = 0; i < n; i++) {
            if (i == 0) {
                unsigned char local = D_004FFC04->b250;
                if (D_004FFBB2 == 0)
                    local = 1;
                if (!local) {
                    if (D_00493A60 == -1)
                        D_00493A60 = 0;
                    p = NewPlayer(r);
                } else {
                    {
                        AllocGuard g;
                        p = (NpcObj*)cMemMan_Allocate(0, 0x35A0, D_0049EE88, 0x32E);
                    }
                    if (p)
                        p = cHuman_ctor_cPopulationR_eCharacterType_SKLP_cGeneratorParamsP(p, r, 1, 0, 0);
                }
                cGameSystem_SetPlayer(g_Game, p->actorId);
                p->SetActive(1);
                nGobjManager_SetPlayer(p);
                if (D_0055DE94) {
                    int kind = SKL_FindSex(p->appearance);
                    int idx = ((p->flagsC & 0x7F000000) >> 24) - 1;
                    if (idx < 0)
                        idx = 0;
                    int v = g_AgentPartCache.tbl[kind][idx];
                    if (v)
                        cMan_AddDisguise(p->sub60, v);
                }
            } else {
                {
                    AllocGuard g;
                    p = (NpcObj*)cMemMan_Allocate(0, 0x35A0, D_0049EE88, 0x347);
                }
                if (p)
                    p = cHuman_ctor_cPopulationR_eCharacterType_SKLP_cGeneratorParamsP(p, r, 2, 0, 0);
            }
            void* reg = g_ActorList;
            p->reg = reg;
            cBaseObjList_Add(reg, p);
        }
    }
    if (!(unsigned char)cPopulation_SeekBlock(r, 0x3A4E4547)) {
        cFileMan_dtor(&e, -1);
        return;
    }
    {
        int n = *(int*)r->cur;
        r->cur += 4;
        for (int i = 0; i < n; i++) {
            r->cur += 8;
            SkipStr(r);
            Align(r);
            r->cur += 0x34;
            r->cur += 4;
            r->cur += 4;
            int cnt = *(int*)r->cur;
            r->cur += 4;
            r->cur += cnt / 2 * 8 + 0xC;
            if (r->unk0 >= 0x3E) {
                r->cur += 1;
                Align(r);
            }
            r->cur += 1;
            Align(r);
            if (r->unk0 >= 0x32)
                r->cur += 4;
            SkipStr(r);
            Align(r);
        }
    }
    Monster_MonsterPartMemory(&g_AgentPartCache);
    cFileMan_dtor(&e, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C1E70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C1E70 */

/* merge_units: begin func_001C24D0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct ActTerrain {
    char pad[0x4c];
    int kind;
};

extern "C" {
#if 0 /* merge_units */
void* GetMachine();
#endif /* merge_units */
#define GetMachine() (GetMachine()) /* merge_units */


#if 0 /* merge_units */
void cMachine_ShowLoadingScreen(void*, const char*, int);
#endif /* merge_units */
#define cMachine_ShowLoadingScreen(a0, a1, a2) (cMachine_ShowLoadingScreen((a0), (char *)(a1), (a2))) /* merge_units */


#if 0 /* merge_units */
void* cMemMan_Allocate(int, int, const char*, int);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (char *)(a2), (a3))) /* merge_units */


ActTerrain* nGobjManager_LookupGOBJ_int_int(int, int);
void cTerrain_InitializeActivation_cPopulationR(void*, PopReader*);
void cTerrain_InitializeActivation_cPopulationR_cArrayP(void*, PopReader*, LoaderOwnedVec*);
void std_vector_imp_cObjectId_reserve(void*, int);
void std_vector_imp_cObjectId_insert(void*, int*, int, int*);
void std_vector_cObjectId_ctor_void(void*);
void std_vector_deleter_cObjectId_clear(void*);
void std_vector_deleter_cObjectId_dtor(void*, int);
extern char D_0049EE88[], D_0049F0D0[];
extern int D_004EE780;
}

static inline int ActRead(PopReader* r)
{
    int n = *(int*)r->cur;
    r->cur += 4;
    return n;
}

/* new KeyVector (owning) */
static inline LoaderOwnedVec* NewVec()
{
    LoaderOwnedVec* p;
    {
        AllocGuard g;
        p = (LoaderOwnedVec*)cMemMan_Allocate(0, 0x10, D_0049EE88, 0x2b0);
    }
    if (p) {
        std_vector_cObjectId_ctor_void(p);
        p->owns = 1;
    }
    return p;
}

static inline void Push(LoaderOwnedVec* v, int* k)
{
    std_vector_imp_cObjectId_insert(v, v->vec.data + v->vec.count, 1, k);
}

extern "C" void cLoader_LoadActivation(void* unused, PopReader* r)
{
    int key;
    cMachine_ShowLoadingScreen(GetMachine(), D_0049F0D0, 0);
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    if ((unsigned char)cPopulation_SeekBlock(r, 0x3a544341)) {
        int n = ActRead(r);
        for (int i = 0; i < n; i++) {
            int a = ActRead(r), b = ActRead(r);
            ActTerrain* t = nGobjManager_LookupGOBJ_int_int(a, b);
            if (t && t->kind == D_004EE780)
                cTerrain_InitializeActivation_cPopulationR(t, r);
            else {
                int count = ActRead(r);
                r->cur += count * 4;
            }
        }
    } else if ((unsigned char)cPopulation_SeekBlock(r, 0x3a4c4341)) {
        int n = ActRead(r);
        LoaderOwnedVec** lists;
        int bytes = n * 4;
        {
            AllocGuard g;
            lists = (LoaderOwnedVec**)cMemMan_Allocate(0, bytes, D_0049EE88, 0x2a8);
        }
        for (int i = 0; i < n; i++) {
            int count = ActRead(r);
            lists[i] = NewVec();
            std_vector_imp_cObjectId_reserve(lists[i], count / 2);
            for (int j = 0; j < count / 2; j++) {
                int a = ActRead(r), b = ActRead(r);
                key = b | (a << 16);
                Push(lists[i], &key);
            }
        }
        if ((unsigned char)cPopulation_SeekBlock(r, 0x3a4c4e49)) {
            int count = ActRead(r);
            for (int i = 0; i < count; i++) {
                int a = ActRead(r), b = ActRead(r), index = ActRead(r);
                ActTerrain* t = nGobjManager_LookupGOBJ_int_int(a, b);
                if (t && t->kind == D_004EE780)
                    cTerrain_InitializeActivation_cPopulationR_cArrayP(t, r, lists[index]);
            }
        }
        for (int i = 0; i < n; i++) {
            std_vector_deleter_cObjectId_clear(lists[i]);
            LoaderOwnedVec* p = lists[i];
            {
                AllocGuard g;
                if (p) {
                    if (p) {
                        if (p)
                            std_vector_deleter_cObjectId_dtor(p, 0);
                    }
                }
                cMemMan_Deallocate(0, p, D_0049EE88, 0x2e1);
            }
        }
        {
            AllocGuard g;
            cMemMan_Deallocate(0, lists, D_0049EE88, 0x2e4);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C24D0(void) {}
#undef GetMachine /* merge_units */
#undef cMachine_ShowLoadingScreen /* merge_units */
#undef cMemMan_Allocate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C24D0 */
