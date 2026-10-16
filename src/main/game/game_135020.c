/*
 * main/game: range (2 files, 00135020-001350E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "cmessage.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_00135020 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern void* D_004EA0C0;
void func_00139DF0(void* p, short f);
}
extern "C" void func_00135020(void)
{
    void* p = D_004EA0C0;
    if (p) {
        {
            AllocGuard g;
            if (p) { if (p) { if (p) func_00139DF0(p, 0); } }
            Mem_Free(0, p, "collision.hh", 0xAF2);
        }
        D_004EA0C0 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00135020(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00135020 */

/* merge_units: begin func_001350E0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
}struct Cfg_1350E0 { char pad[0xC4]; int fC4; };
struct Sub_1350E0 { char pad[0x188]; Cfg_1350E0 f188; };
struct Desc_1350E0 { int a; unsigned char b4; unsigned char b5; unsigned char b6; unsigned char b7; };
struct Pl_1350E0 { char pad[0x30]; int f30; char pad34[0x174 - 0x34]; unsigned char b174; unsigned char b175; unsigned char b176; };
struct Cam_1350E0 { char pad[0x20]; int f20; };
struct Coll_1350E0 { char pad[0xC]; unsigned char bC; };
struct World_1350E0 {
    char pad0[0x3C];
    char f3C[0x80 - 0x3C];
    Cam_1350E0* f80;
    char pad84[0x88 - 0x84];
    int f88;
    void* f8C;
    Coll_1350E0* f90;
    char pad94[0x98 - 0x94];
    Coll_1350E0* f98;
    char pad9C[0xB4 - 0x9C];
    Sub_1350E0* fB4;
    char padB8[0xBC - 0xB8];
    Pl_1350E0* fBC;
    char padC0[0xEC - 0xC0];
    void* fEC;
    char padF0[0x140 - 0xF0];
    char f140[0x1C4 - 0x140];
    unsigned char b1C4;
    unsigned char b1C5;
    unsigned char b1C6;
    unsigned char b1C7;
    char pad1C8[0x1DC - 0x1C8];
    Desc_1350E0* f1DC;
    char pad1E0[0x1F0 - 0x1E0];
    int f1F0;
    void* f1F4;
    void* f1F8;
};
struct Req_1350E0 { char pad[0x48]; char partA[0xE4 - 0x48]; char partB[0x190 - 0xE4]; };
struct EMsg_1350E0 { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; };
struct Path_1350E0 { char pad[0xA0]; };
struct Los_1350E0 { void* vtbl; char pad[0x48]; };
struct Zone_1350E0 { int a; unsigned char b4; };
struct Shd_1350E0 { char pad[0xC]; unsigned char bC; };
struct Snd_1350E0 { char pad[0x278]; unsigned char b278; };
extern "C" {
extern unsigned char D_00489BA8;
extern char D_0048B2F8[];
extern char D_0049A890[];
extern char D_0049A908[];
extern char D_0049AA60[];
extern char D_0049AA70[];
extern char D_0049AA90[];
extern char D_0049AAA8[];
extern char D_0049AAB0[];
extern char D_0049AAC0[];
extern char D_004D90E0[];
extern char D_004D9100[];
extern char D_004DAE30[];
extern char D_004F2CC0[];
extern char D_004F53F0[];
extern char D_004FFB50[];
extern char D_004FFC90[];
extern Shd_1350E0* D_0053924C;
extern char D_0053B540[];
extern char D_0053BB90[];
extern char D_00543790[];
extern char D_00555070[];
void* Agent_GetSelected(World_1350E0* w, int i);
int Archive_Open(void* a, char* name, int b, int c);
void Awards_Init(World_1350E0* w);
void ColScratch_Init(int a, int b, int c, int d);
void EffectMsg_WrapRequest(EMsg_1350E0* m, Req_1350E0* r);
int IArcade_Init(void* p);
void IdMgr_Init(void);
void Loader_LoadLevelData(int a, void* b);
void Loc_LoadMissionPool(char* a, char* b);
char* Loc_LookupText(char* s);
void LosProvider_Create(int n);
void LosReceiver_Construct(Los_1350E0* p, int n);
void* Mem_Alloc(int pool, int size, char* file, int line);
void NameSlot_SetName(World_1350E0* w, int i, char* s);
void ScalarCollection_Init(void* p);
void ScriptMgr_CallFunction(void* m, char* name, int a);
void ScriptMgr_LoadScript(void* m, char* name, int a);
void Script_StartLevel(void* m);
void* Service_Lookup(void* a, void* b);
void ShadowMgr_Construct(void* p);
void SkaLevel_CloseArchive(int a, void* b);
void SkaLevel_OpenArchive(int a, void* b);
void Skel_LoadCommonModels(int a, void* b);
void SoundRequest_Ctor(Req_1350E0* r, int kind, char* name, int a, int b);
void* World_GetActorArray(void);
void World_SetupView(World_1350E0* w);
void World_UpdateZoneTrackers(void* z);
void func_0012F630(World_1350E0* w);
void Game_CreateHud(World_1350E0* w);
void func_001360D0(int n);
void func_001365E0(void* p);
void func_001366F0(void* p);
void Game_LoadParResources(void* p);
Zone_1350E0* func_0013D770(void* z, int id);
void* func_0013D9F0(void);
void LoadingScreen_Start(void* a, int b, char* c);
Snd_1350E0* App_GetInstance(void);
void func_0016F510(void);
void Human_InitStatics(void);
void func_001C01D0(int a, void* b);
void SoundMgr_LoadLevel(void* p);
void SoundMgr_Init(void* p);
void func_00257380(void);
void func_0026BE70(unsigned char b);
void* DecalMgr_ctor(void* p, int a, int b);
void LevelSelect_FindByName(void* a, void* b);
void func_00335D50(void* a, int b);
int FileMan_FindMember(Path_1350E0* p);
void FileMan_Release(void* p, int f);
void func_0036E4B0(Path_1350E0* p, char* name, int a, int b);
void ParticleSystem_Construct(void* p, int n);
void func_003CAC40(World_1350E0* w, void* p);
void func_003E2140(void* m, int a);
void MaterialProps_ResolveEffects(void* a, int b);
void GobjScopeBase_Ctor(void* p, int n, void* arr);
void MotionManager_Init(void);
void func_004703B0(void);
}

extern "C" void World_Setup(World_1350E0* w)
{
    char name[0x30];
    char path[0x80];
    Path_1350E0 pf;
    EMsg_1350E0 m;
    char arc[0x80];
    Req_1350E0 req;
    CMsg cm;
    int i;
    void* svc;

    {
        Cfg_1350E0* c = &w->fB4->f188;
        if (c->fC4 == -1) LevelSelect_FindByName(c, w->f140);
    }
    func_0012F630(w);
    func_003E2140(D_00555070, IArcade_Init(w->f3C));
    Awards_Init(w);
    for (i = 0; i < 4; i++) {
        if (D_00489BA8) {
            sprintf(name, D_0049AA60, i);
            NameSlot_SetName(w, i, Loc_LookupText(name));
        }
    }
    func_00335D50(Agent_GetSelected(w, -1), 1);
    Skel_LoadCommonModels(w->f88, w->f3C);
    IdMgr_Init();
    {
        void* p;
        { if (D_00533880) Alloc_Lock(9); D_00533888++; p = Mem_Alloc(0, 0x24, D_0049A890, 0x1E3); if (D_00533880) Alloc_Unlock(9); D_00533888--; }
        if (p) GobjScopeBase_Ctor(p, 0x82, World_GetActorArray());
        w->f1F4 = p;
    }
    {
        void* p;
        { if (D_00533880) Alloc_Lock(9); D_00533888++; p = Mem_Alloc(0, 0x24, D_0049A890, 0x1E4); if (D_00533880) Alloc_Unlock(9); D_00533888--; }
        if (p) GobjScopeBase_Ctor(p, 0x3E8, World_GetActorArray());
        w->f1F8 = p;
    }
    func_00257380();
    App_GetInstance();
    if (w->f98 == 0) {
        Coll_1350E0* p;
        { if (D_00533880) Alloc_Lock(9); D_00533888++; p = (Coll_1350E0*)Mem_Alloc(0, 0x10, D_0049A890, 0x1EC); if (D_00533880) Alloc_Unlock(9); D_00533888--; }
        if (p) {
            func_001366F0(p);
            p->bC = 1;
        }
        w->f98 = p;
    }
    if (w->f90 == 0) {
        Coll_1350E0* p;
        { if (D_00533880) Alloc_Lock(9); D_00533888++; p = (Coll_1350E0*)Mem_Alloc(0, 0x10, D_0049A890, 0x1EF); if (D_00533880) Alloc_Unlock(9); D_00533888--; }
        if (p) {
            func_001365E0(p);
            p->bC = 1;
        }
        w->f90 = p;
    }
    Loc_LoadMissionPool(D_0048B2F8, D_004FFC90);
    sprintf(path, D_0049AA70, D_0048B2F8, D_004FFC90);
    func_0036E4B0(&pf, path, 0, 0);
    if ((unsigned char)FileMan_FindMember(&pf)) {
        sprintf(path, D_0049AA90, D_0048B2F8);
    }
    LoadingScreen_Start(App_GetInstance(), 0, path);
    ParticleSystem_Construct(D_0053B540, 0x1388);
    {
        void* p;
        { if (D_00533880) Alloc_Lock(9); D_00533888++; p = Mem_Alloc(0, 0x230, D_0049A890, 0x20C); if (D_00533880) Alloc_Unlock(9); D_00533888--; }
        if (p) p = DecalMgr_ctor(p, 0x64, 0x14);
        w->fEC = p;
    }
    {
        void* p;
        { if (D_00533880) Alloc_Lock(9); D_00533888++; p = Mem_Alloc(0, 0xC, D_0049A890, 0x20F); if (D_00533880) Alloc_Unlock(9); D_00533888--; }
        if (p) ScalarCollection_Init(p);
        w->f8C = p;
    }
    func_0016F510();
    ScriptMgr_LoadScript(D_00555070, D_0049AAA8, 0);
    ScriptMgr_CallFunction(D_00555070, D_0049AAB0, 0);
    ColScratch_Init(0x96, 0, 0, 0);
    LosProvider_Create(0x12C);
    MotionManager_Init();
    Human_InitStatics();
    ColScratch_Init(0, 0, 0, 0);
    func_001360D0(0x320);
    func_0026BE70(w->f1DC->b5);
    {
        Los_1350E0* p;
        { if (D_00533880) Alloc_Lock(9); D_00533888++; p = (Los_1350E0*)Mem_Alloc(0, 0x4C, D_0049A890, 0x22E); if (D_00533880) Alloc_Unlock(9); D_00533888--; }
        if (p) {
            LosReceiver_Construct(p, 0x1E);
            p->vtbl = D_004D9100;
        }
        func_003CAC40(w, p);
    }
    svc = Service_Lookup(w, D_004F2CC0);
    if (D_00489BA8) SoundMgr_Init(svc);
    SoundMgr_LoadLevel(svc);
    SoundRequest_Ctor(&req, 5, D_0049A908, 0, 0);
    EffectMsg_WrapRequest(&m, &req);
    FileMan_Release(req.partB, -1);
    FileMan_Release(req.partA, -1);
    m.flag = 1;
    Event_Send(&m, D_004FFB50, 0);
    func_001C01D0(w->f88, w->f3C);
    Loader_LoadLevelData(w->f88, w->f3C);
    sprintf(arc, D_0049AAC0, D_0048B2F8);
    MaterialProps_ResolveEffects(D_0053BB90, Archive_Open(w->f3C, arc, 0, 0));
    Game_LoadParResources(w->f3C);
    World_SetupView(w);
    Game_CreateHud(w);
    Event_Construct(&cm, D_004F53F0);
    cm.vtable = D_004D90E0;
    Event_Send(&cm, w->fBC, 1);
    cm.vtable = D_004D90E0;
    cMessage_dtor(&cm, 0);
    w->fBC->b174 = w->f1DC->b4;
    w->fBC->b175 = w->f1DC->b6;
    w->fBC->b176 = w->f1DC->b7;
    w->f80->f20 = w->fBC->f30;
    SkaLevel_OpenArchive(w->f88, w->f3C);
    Script_StartLevel(D_00555070);
    func_004703B0();
    SkaLevel_CloseArchive(w->f88, w->f3C);
    ShadowMgr_Construct(D_00543790);
    D_0053924C->bC = 1;
    {
        Zone_1350E0* z = func_0013D770(func_0013D9F0(), w->fBC->f30);
        z->b4 = 1;
    }
    World_UpdateZoneTrackers(func_0013D9F0());
    D_00489BA8 = 0;
    w->b1C4 = 0;
    w->b1C5 = 0;
    w->b1C6 = 0;
    w->b1C7 = 0;
    {
        Snd_1350E0* s = App_GetInstance();
        s->b278 = 1;
    }
    w->f1F0 = 0;
    m.vtbl = D_004DAE30;
    FileMan_Release(m.partB, -1);
    FileMan_Release(m.partA, -1);
    cMessage_dtor(&m, 0);
    FileMan_Release(&pf, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001350E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001350E0 */
