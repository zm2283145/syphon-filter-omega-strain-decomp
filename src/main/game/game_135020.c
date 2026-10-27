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
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_00135020 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern void* D_004EA0C0;
void func_00139DF0(void* p, short f);
}
extern "C" void cCollisionSystem_cBox_UnInitStatics(void)
{
    void* p = D_004EA0C0;
    if (p) {
        {
            AllocGuard g;
            if (p) { if (p) { if (p) func_00139DF0(p, 0); } }
            cMemMan_Deallocate(0, p, "collision.hh", 0xAF2);
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
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void EnableIntc(int id);
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
extern char g_Game[];
extern char g_LevelDirName[];
extern Shd_1350E0* D_0053924C;
extern char D_0053B540[];
extern char D_0053BB90[];
extern char D_00543790[];
extern char D_00555070[];
void* cGameSystem_GetAgentData(World_1350E0* w, int i);
int cHogList_Open(void* a, char* name, int b, int c);
void cGameSystem_InitAgentData(World_1350E0* w);
void nCollision_InitStatics(int a, int b, int c, int d);
void EffectMsg_WrapRequest(EMsg_1350E0* m, Req_1350E0* r);
int OpenScriptHog(void* p);
void nGobjManager_InitIDs(void);
void cLoader_LoadPop(int a, void* b);
void nGlobalization_LoadLevelStrings(char* a, char* b);
char* nGlobalization_GetString_charP(char* s);
void cLosRequest_cCollisionModelList_Game_InitStatics(int n);
void LosReceiver_Construct(Los_1350E0* p, int n);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cGameSystem_SetClientPlayerName(World_1350E0* w, int i, char* s);
void std_list_deleter_voidPtr_ctor_void(void* p);
void cScriptInterpreter_CallFunction(void* m, char* name, int a);
void cScriptInterpreter_LoadScript(void* m, char* name, int a);
void cScriptInterpreter_ExecInitScript(void* m);
void* cSystemContainer_GetSystem(void* a, void* b);
void cShadowMan_Init(void* p);
void cLoader_CloseHogWithLevelSpecificAnimations(int a, void* b);
void cLoader_OpenHogWithLevelSpecificAnimations_ForAccessByInitScript(int a, void* b);
void cLoader_LoadSkeletons(int a, void* b);
void cSndFx_ctor_int_charP_cGOBJP_int(Req_1350E0* r, int kind, char* name, int a, int b);
void* nGobjManager_GetGOBJList(void);
void cGameSystem_CreatePlayerCameraAndScene(World_1350E0* w);
void cSceneManager_UpdateActivation(void* z);
void cGameSystem_InitMEM(World_1350E0* w);
void cGameSystem_LoadHud(World_1350E0* w);
void cCollisionSystem_cBox_InitStatics(int n);
void std_vector_cNodePtr_ctor(void* p);
void std_vector_cArray_int_ctor(void* p);
void LoadRequestedParticles(void* p);
Zone_1350E0* cSceneManager_GetSceneBelongingTo(void* z, int id);
void* GetSceneManager(void);
void cMachine_SetLoadingScreen(void* a, int b, char* c);
Snd_1350E0* GetMachine(void);
void cAI_SystemInit(void);
void cHuman_InitStatics(void);
void cLoader_LoadCoreAnimations(int a, void* b);
void cGameSound_Load(void* p);
void cGameSound_Init(void* p);
void cBackpack_InitLevel(void);
void nRumbleManager_SetEnabled(unsigned char b);
void* cDecalMan_ctor(void* p, int a, int b);
void MissionSelectData_SelectMissionByName(void* a, void* b);
void cAgentData_StartLevel(void* a, int b);
int cFileMan_Open(Path_1350E0* p);
void cFileMan_dtor(void* p, int f);
void cFileMan_ctor_charP_cFileIOP_bool(Path_1350E0* p, char* name, int a, int b);
void cParticleSystem_Init(void* p, int n);
void cSystemContainer_AddSystem(World_1350E0* w, void* p);
void cScriptInterpreter_SetHog(void* m, int a);
void cMaterialPropertiesTable_Init_cHogFileR(void* a, int b);
void cBaseObjList_ctor(void* p, int n, void* arr);
void cMotionManager_InitStatics(void);
void cInventory_LoadShapes(void);
}

extern "C" void cGameSystem_Init(World_1350E0* w)
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
        if (c->fC4 == -1) MissionSelectData_SelectMissionByName(c, w->f140);
    }
    cGameSystem_InitMEM(w);
    cScriptInterpreter_SetHog(D_00555070, OpenScriptHog(w->f3C));
    cGameSystem_InitAgentData(w);
    for (i = 0; i < 4; i++) {
        if (D_00489BA8) {
            sprintf(name, D_0049AA60, i);
            cGameSystem_SetClientPlayerName(w, i, nGlobalization_GetString_charP(name));
        }
    }
    cAgentData_StartLevel(cGameSystem_GetAgentData(w, -1), 1);
    cLoader_LoadSkeletons(w->f88, w->f3C);
    nGobjManager_InitIDs();
    {
        void* p;
        { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; p = cMemMan_Allocate(0, 0x24, D_0049A890, 0x1E3); if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
        if (p) cBaseObjList_ctor(p, 0x82, nGobjManager_GetGOBJList());
        w->f1F4 = p;
    }
    {
        void* p;
        { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; p = cMemMan_Allocate(0, 0x24, D_0049A890, 0x1E4); if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
        if (p) cBaseObjList_ctor(p, 0x3E8, nGobjManager_GetGOBJList());
        w->f1F8 = p;
    }
    cBackpack_InitLevel();
    GetMachine();
    if (w->f98 == 0) {
        Coll_1350E0* p;
        { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; p = (Coll_1350E0*)cMemMan_Allocate(0, 0x10, D_0049A890, 0x1EC); if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
        if (p) {
            std_vector_cArray_int_ctor(p);
            p->bC = 1;
        }
        w->f98 = p;
    }
    if (w->f90 == 0) {
        Coll_1350E0* p;
        { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; p = (Coll_1350E0*)cMemMan_Allocate(0, 0x10, D_0049A890, 0x1EF); if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
        if (p) {
            std_vector_cNodePtr_ctor(p);
            p->bC = 1;
        }
        w->f90 = p;
    }
    nGlobalization_LoadLevelStrings(D_0048B2F8, g_LevelDirName);
    sprintf(path, D_0049AA70, D_0048B2F8, g_LevelDirName);
    cFileMan_ctor_charP_cFileIOP_bool(&pf, path, 0, 0);
    if ((unsigned char)cFileMan_Open(&pf)) {
        sprintf(path, D_0049AA90, D_0048B2F8);
    }
    cMachine_SetLoadingScreen(GetMachine(), 0, path);
    cParticleSystem_Init(D_0053B540, 0x1388);
    {
        void* p;
        { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; p = cMemMan_Allocate(0, 0x230, D_0049A890, 0x20C); if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
        if (p) p = cDecalMan_ctor(p, 0x64, 0x14);
        w->fEC = p;
    }
    {
        void* p;
        { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; p = cMemMan_Allocate(0, 0xC, D_0049A890, 0x20F); if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
        if (p) std_list_deleter_voidPtr_ctor_void(p);
        w->f8C = p;
    }
    cAI_SystemInit();
    cScriptInterpreter_LoadScript(D_00555070, D_0049AAA8, 0);
    cScriptInterpreter_CallFunction(D_00555070, D_0049AAB0, 0);
    nCollision_InitStatics(0x96, 0, 0, 0);
    cLosRequest_cCollisionModelList_Game_InitStatics(0x12C);
    cMotionManager_InitStatics();
    cHuman_InitStatics();
    nCollision_InitStatics(0, 0, 0, 0);
    cCollisionSystem_cBox_InitStatics(0x320);
    nRumbleManager_SetEnabled(w->f1DC->b5);
    {
        Los_1350E0* p;
        { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; p = (Los_1350E0*)cMemMan_Allocate(0, 0x4C, D_0049A890, 0x22E); if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
        if (p) {
            LosReceiver_Construct(p, 0x1E);
            p->vtbl = D_004D9100;
        }
        cSystemContainer_AddSystem(w, p);
    }
    svc = cSystemContainer_GetSystem(w, D_004F2CC0);
    if (D_00489BA8) cGameSound_Init(svc);
    cGameSound_Load(svc);
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 5, D_0049A908, 0, 0);
    EffectMsg_WrapRequest(&m, &req);
    cFileMan_dtor(req.partB, -1);
    cFileMan_dtor(req.partA, -1);
    m.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 0);
    cLoader_LoadCoreAnimations(w->f88, w->f3C);
    cLoader_LoadPop(w->f88, w->f3C);
    sprintf(arc, D_0049AAC0, D_0048B2F8);
    cMaterialPropertiesTable_Init_cHogFileR(D_0053BB90, cHogList_Open(w->f3C, arc, 0, 0));
    LoadRequestedParticles(w->f3C);
    cGameSystem_CreatePlayerCameraAndScene(w);
    cGameSystem_LoadHud(w);
    cMessage_ctor_cMessageNameR(&cm, D_004F53F0);
    cm.vtable = D_004D90E0;
    QueueMessage_cMessageR_cSystemP_int(&cm, w->fBC, 1);
    cm.vtable = D_004D90E0;
    cMessage_dtor(&cm, 0);
    w->fBC->b174 = w->f1DC->b4;
    w->fBC->b175 = w->f1DC->b6;
    w->fBC->b176 = w->f1DC->b7;
    w->f80->f20 = w->fBC->f30;
    cLoader_OpenHogWithLevelSpecificAnimations_ForAccessByInitScript(w->f88, w->f3C);
    cScriptInterpreter_ExecInitScript(D_00555070);
    cInventory_LoadShapes();
    cLoader_CloseHogWithLevelSpecificAnimations(w->f88, w->f3C);
    cShadowMan_Init(D_00543790);
    D_0053924C->bC = 1;
    {
        Zone_1350E0* z = cSceneManager_GetSceneBelongingTo(GetSceneManager(), w->fBC->f30);
        z->b4 = 1;
    }
    cSceneManager_UpdateActivation(GetSceneManager());
    D_00489BA8 = 0;
    w->b1C4 = 0;
    w->b1C5 = 0;
    w->b1C6 = 0;
    w->b1C7 = 0;
    {
        Snd_1350E0* s = GetMachine();
        s->b278 = 1;
    }
    w->f1F0 = 0;
    m.vtbl = D_004DAE30;
    cFileMan_dtor(m.partB, -1);
    cFileMan_dtor(m.partA, -1);
    cMessage_dtor(&m, 0);
    cFileMan_dtor(&pf, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001350E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001350E0 */
