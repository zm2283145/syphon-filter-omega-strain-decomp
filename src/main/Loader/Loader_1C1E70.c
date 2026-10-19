/*
 * main/Loader: range (2 files, 001C1E70-001C24D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
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
int Mem_Free();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001C1E70 */
#pragma push /* merge_units */
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
extern char D_0048B2F8[];
extern char D_0057124C[], D_005711B0[];
extern char g_Game[];
extern NetState* D_004FFC04;
extern unsigned char D_004FFBB2;
extern signed char D_00493A60;
extern NpcColor D_0055D510[];
extern int D_0055DE94;
extern BodyTbl g_AgentPartCache;
extern void* g_ActorList;
void* Mem_Alloc(int pool, int size, char* file, int line);
void Loader_UpdateLoadingScreen(void* a, char* name, int x);
void* App_GetInstance(void);
int Archive_Open(void* a, char* name, int b, int c);
void Hog_Register(void* hog, char* name, int h, int b);
void TexCache_AddThermalTextures(void* hog);
void Expression_Init(void);
NpcObj* Npc_Construct(void* p, PopReader* r, int kind, NpcColor* color, int x);
void World_RegisterActor(void* w, int id);
void Player_SetLocal(NpcObj* o);
int Appearance_GetBodyKind(void* a);
void func_00391020(void* a, int b);
void ObjRegistry_AppendRecursive(void* reg, NpcObj* o);
void func_00403FC0(void* a);
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
        p = (NpcObj*)Mem_Alloc(0, 0x35A0, D_0049EE88, 0x32A);
    }
    if (p)
        p = Npc_Construct(p, r, 1, &D_0055D510[D_00493A60], 0);
    return p;
}

extern "C" void Pop_LoadNPC(void* unused, PopReader* r, void* arc)
{
    char thermal[128];
    char name[128];
    FileManEntry e;
    Resource_Construct(&e);
    Loader_UpdateLoadingScreen(App_GetInstance(), D_0049F050, 0);
    sprintf(thermal, D_0049F070, D_0048B2F8);
    sprintf(name, D_0049F090, D_0048B2F8);
    Hog_Register(D_0057124C, D_0049F0A8, Archive_Open(arc, name, 1, 0), 1);
    Hog_Register(D_005711B0, D_0049F0B8, Archive_Open(arc, thermal, 1, 0), 1);
    TexCache_AddThermalTextures(D_005711B0);
    Expression_Init();
    if (!(unsigned char)Pop_FindTag(r, 0x3A43504E)) {
        FileMan_Release(&e, -1);
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
                        p = (NpcObj*)Mem_Alloc(0, 0x35A0, D_0049EE88, 0x32E);
                    }
                    if (p)
                        p = Npc_Construct(p, r, 1, 0, 0);
                }
                World_RegisterActor(g_Game, p->actorId);
                p->SetActive(1);
                Player_SetLocal(p);
                if (D_0055DE94) {
                    int kind = Appearance_GetBodyKind(p->appearance);
                    int idx = ((p->flagsC & 0x7F000000) >> 24) - 1;
                    if (idx < 0)
                        idx = 0;
                    int v = g_AgentPartCache.tbl[kind][idx];
                    if (v)
                        func_00391020(p->sub60, v);
                }
            } else {
                {
                    AllocGuard g;
                    p = (NpcObj*)Mem_Alloc(0, 0x35A0, D_0049EE88, 0x347);
                }
                if (p)
                    p = Npc_Construct(p, r, 2, 0, 0);
            }
            void* reg = g_ActorList;
            p->reg = reg;
            ObjRegistry_AppendRecursive(reg, p);
        }
    }
    if (!(unsigned char)Pop_FindTag(r, 0x3A4E4547)) {
        FileMan_Release(&e, -1);
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
    func_00403FC0(&g_AgentPartCache);
    FileMan_Release(&e, -1);
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
void* App_GetInstance();
#endif /* merge_units */
#define App_GetInstance() (App_GetInstance()) /* merge_units */

#if 0 /* merge_units */
void Loader_UpdateLoadingScreen(void*, const char*, int);
#endif /* merge_units */
#define Loader_UpdateLoadingScreen(a0, a1, a2) (Loader_UpdateLoadingScreen((a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void* Mem_Alloc(int, int, const char*, int);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) (Mem_Alloc((a0), (a1), (char *)(a2), (a3))) /* merge_units */

ActTerrain* IdMgr_FindCollision(int, int);
void Terrain_ReadActRecord(void*, PopReader*);
void Terrain_ApplyInl(void*, PopReader*, LoaderOwnedVec*);
void KeyVector_Reserve(void*, int);
void KeyVector_PushBack(void*, int*, int, int*);
void func_001C29F0(void*);
void Actor_VirtualLeaf175230(void*);
void func_00175240(void*, int);
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
        p = (LoaderOwnedVec*)Mem_Alloc(0, 0x10, D_0049EE88, 0x2b0);
    }
    if (p) {
        func_001C29F0(p);
        p->owns = 1;
    }
    return p;
}

static inline void Push(LoaderOwnedVec* v, int* k)
{
    KeyVector_PushBack(v, v->vec.data + v->vec.count, 1, k);
}

extern "C" void Loader_InitActivationMap(void* unused, PopReader* r)
{
    int key;
    Loader_UpdateLoadingScreen(App_GetInstance(), D_0049F0D0, 0);
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    if ((unsigned char)Pop_FindTag(r, 0x3a544341)) {
        int n = ActRead(r);
        for (int i = 0; i < n; i++) {
            int a = ActRead(r), b = ActRead(r);
            ActTerrain* t = IdMgr_FindCollision(a, b);
            if (t && t->kind == D_004EE780)
                Terrain_ReadActRecord(t, r);
            else {
                int count = ActRead(r);
                r->cur += count * 4;
            }
        }
    } else if ((unsigned char)Pop_FindTag(r, 0x3a4c4341)) {
        int n = ActRead(r);
        LoaderOwnedVec** lists;
        int bytes = n * 4;
        {
            AllocGuard g;
            lists = (LoaderOwnedVec**)Mem_Alloc(0, bytes, D_0049EE88, 0x2a8);
        }
        for (int i = 0; i < n; i++) {
            int count = ActRead(r);
            lists[i] = NewVec();
            KeyVector_Reserve(lists[i], count / 2);
            for (int j = 0; j < count / 2; j++) {
                int a = ActRead(r), b = ActRead(r);
                key = b | (a << 16);
                Push(lists[i], &key);
            }
        }
        if ((unsigned char)Pop_FindTag(r, 0x3a4c4e49)) {
            int count = ActRead(r);
            for (int i = 0; i < count; i++) {
                int a = ActRead(r), b = ActRead(r), index = ActRead(r);
                ActTerrain* t = IdMgr_FindCollision(a, b);
                if (t && t->kind == D_004EE780)
                    Terrain_ApplyInl(t, r, lists[index]);
            }
        }
        for (int i = 0; i < n; i++) {
            Actor_VirtualLeaf175230(lists[i]);
            LoaderOwnedVec* p = lists[i];
            {
                AllocGuard g;
                if (p) {
                    if (p) {
                        if (p)
                            func_00175240(p, 0);
                    }
                }
                Mem_Free(0, p, D_0049EE88, 0x2e1);
            }
        }
        {
            AllocGuard g;
            Mem_Free(0, lists, D_0049EE88, 0x2e4);
        }
    }
}
#undef App_GetInstance /* merge_units */
#undef Loader_UpdateLoadingScreen /* merge_units */
#undef Mem_Alloc /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C24D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C24D0 */
