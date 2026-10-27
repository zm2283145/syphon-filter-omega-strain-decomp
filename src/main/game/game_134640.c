/*
 * main/game: range (2 files, 00134640-00134E00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_00134640 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VDel_134640 { virtual void Del(int f); };
struct List_134640 { int x; char head[4]; void* first; };
struct V3_134640 { int a; int b; int c; };
struct World_134640 {
    char pad0[0x80];
    void* f80;
    void* f84;
    void* f88;
    void* f8C;
    char pad90[0x9C - 0x90];
    List_134640 l9C;
    char padA8[0xC4 - 0xA8];
    List_134640 lC4;
    void* fD0;
    char padD4[0xDC - 0xD4];
    void* fDC;
    void* fE0;
    void* fE4;
    V3_134640* fE8;
    void* fEC;
    char padF0[0x1C5 - 0xF0];
    unsigned char b1C5;
    unsigned char b1C6;
    unsigned char b1C7;
    char pad1C8[0x1E0 - 0x1C8];
    void* f1E0;
    char pad1E4[0x1F4 - 0x1E4];
    void* f1F4;
    void* f1F8;
};
extern "C" {
extern char D_0049A890[];
extern char D_0049AEA0[];
extern char g_LosCheckService[];
extern VDel_134640* D_004EA0B8;
extern char D_004F2CC0[];
extern char D_004F7578[];
extern char g_LightMgr[];
extern int g_VisionNight;
extern int g_VisionThermal;
extern char D_0053B540[];
extern char D_0053BB90[];
extern char D_00543790[];
extern char D_00555070[];
extern char g_AgentPartCache[];
extern unsigned char D_005721B8;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721D8;
extern unsigned char D_005723B0;
extern char g_TargetVisMgr[];
void* GetGOBJActivationMan(void);
void EventQueue_ClearAll(void);
void nGobjManager_RemoveAll(void);
void cLightMan_DeallocateLightSources(void* p);
void ClearMessages(void);
void cNetObj_Clear(void);
void cObjectiveMan_DestroyObjectives(void* p);
void* ObjMan_GetService(void);
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(void* result, void* list, void* first, void* last);
void ScreenFx_Start(void* p, int a, float r, float g, float b, float c);
void cScriptInterpreter_Reset(void* p);
void* cSystemContainer_GetSystem(void* a, void* b);
void cTeam_Reset(void);
void cWaterFx_Purge(void* p);
void cWeaponDB_UnloadLevelSpecific(void* p);
void cGameSystem_DestroySkeletons(World_134640* w);
void cGameSystem_DestroyAnimationSets(World_134640* w);
void cGameSystem_RemoveVUMGOBJNames(World_134640* w);
void cGameSystem_DestroyPlayerCameraAndScene(World_134640* w);
void cGameSystem_ShowEndMissionScreens(World_134640* w, int mode);
void cCollisionSystem_cBox_UnInitStatics(void);
void cGameSystem_ClearNodeGroups(World_134640* w);
void cGameSystem_ClearNodeList(World_134640* w);
void cScene_DeactivateAll(void* p);
void cAI_SystemClear(void);
void ResetInteractBoxes(void);
void cHotboxMan_ClearLists(void* p);
void cEnvMan_Reset(void* p);
void cHuman_UnInitStatics(void);
void cLoader_DeallocateAllAnimationBuffers(void* p);
void cGameSound_StopAllSounds(void* p);
void cGameSound_Unload(void* p);
void cGOBJActivationMan_Clear(void* p);
void cObjectiveMan_DeactivateObjectiveScreen(void* p);
void cTargetManager_Reset(void* p);
void nSfxLoader_UnloadEffects(void);
void cNIEventFXTrack_FreeStringTable(void);
void cHud_dtor(void* p, int f);
void cBackpack_PurgeCrateSaves(void);
void cBackpack_Reset(void);
void cVisionFxMan_ActivateFx(void* p);
void cVisionFxMan_SetMode(void* p, int a, int b);
void nScriptUtils_Reset(void);
void nRumbleManager_StopAll(void);
void nRumbleManager_SetEnabled(int a);
void cTremorManager_dtor(void* p, int f);
void cBulletManager_Reset(void);
void cDecalMan_dtor(void* p, int f);
void cParticleSystem_Clear(void* p);
void nCollision_UnInitStatics(void);
VDel_134640* cSystemContainer_RemoveSystem(World_134640* w, void* s);
void cTextSystem_Clear(void* p);
void* GetTextSystem(void);
void cShadowMan_Purge(void* p);
void cCharActionMsg_DestinationParams_ClearPrevMsg(void);
void cFileStreamMan_Purge(void* p);
void* GetFileStreamMan(void);
void nDynamicSfxList_Clear(void);
void nGlobalization_UnloadLevelStrings(void);
void Monster_dtor(void* p, int a);
void SKLHog_DeleteIdentities(void);
void cMaterialPropertiesTable_Reset(void* p);
void cBaseObjList_dtor(void* p, int f);
void cMotionManager_UnInitStatics(void);
void* cDME_GetLobby(void);
void cDME_StopUpdateThread(void);
void cDME_StartUpdateThread(void);
void Net_CleanupGame(void);
void cDME_Restart(void);
void cNetObjectMgr_Reset(void);
void SFOLobby_ExitGame(void* p);
void cInventory_UnloadShapes(void);
}

static inline void Clear_134640(List_134640* l)
{
    int r;
    void* first;
    void* last;
    last = l->head;
    first = l->first;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, l, &first, &last);
}

static inline void Destroy_134640(void)
{
    if (D_004EA0B8) {
        {
            VDel_134640* p = D_004EA0B8;
            AllocGuard g;
            p->Del(-1);
            cMemMan_Deallocate(0, p, D_0049AEA0, 0xB9);
        }
        D_004EA0B8 = 0;
    }
}

static inline bool TakeFlag_134640(void)
{
    if (D_005721D8) {
        D_005721D8 = 0;
        return true;
    }
    return false;
}

extern "C" void cGameSystem_Reset(World_134640* w)
{
    void* svc;
    int mode;
    bool had;
    cBackpack_PurgeCrateSaves();
    svc = cSystemContainer_GetSystem(w, D_004F2CC0);
    if (svc) cGameSound_StopAllSounds(svc);
    {
        void* om = ObjMan_GetService();
        if (om) cObjectiveMan_DeactivateObjectiveScreen(om);
    }
    {
        void* p = w->fEC;
        AllocGuard g;
        cDecalMan_dtor(p, -1);
        cMemMan_Deallocate(0, p, D_0049A890, 0x2CF);
    }
    w->fEC = 0;
    nRumbleManager_StopAll();
    nRumbleManager_SetEnabled(0);
    {
        void* p = w->f8C;
        AllocGuard g;
        cTremorManager_dtor(p, -1);
        cMemMan_Deallocate(0, p, D_0049A890, 0x2D3);
    }
    w->f8C = 0;
    cVisionFxMan_SetMode(w->fE0, 0, 1);
    ScreenFx_Start(w->fE0, 0, 0.0f, 0.0f, 0.0f, 0.0f);
    cVisionFxMan_ActivateFx(w->fE0);
    cWaterFx_Purge(w->fE4);
    g_VisionNight = 0;
    g_VisionThermal = 0;
    cBulletManager_Reset();
    cNIEventFXTrack_FreeStringTable();
    cScriptInterpreter_Reset(D_00555070);
    nScriptUtils_Reset();
    cTeam_Reset();
    nGlobalization_UnloadLevelStrings();
    cGameSystem_ClearNodeGroups(w);
    cEnvMan_Reset(w->f84);
    Clear_134640(&w->l9C);
    cHotboxMan_ClearLists(w->f80);
    ResetInteractBoxes();
    cTargetManager_Reset(g_TargetVisMgr);
    cMaterialPropertiesTable_Reset(D_0053BB90);
    nDynamicSfxList_Clear();
    cGameSystem_ClearNodeList(w);
    cBackpack_Reset();
    mode = 0;
    if (g_IsMultiplayer) {
        if (TakeFlag_134640()) {
            if (D_005723B0 == 1) mode = 1;
            else if (D_005723B0 == 2) mode = 2;
        }
        cNetObjectMgr_Reset();
        cCharActionMsg_DestinationParams_ClearPrevMsg();
        cDME_Restart();
        if (!w->b1C7) {
            if (cDME_GetLobby()) SFOLobby_ExitGame(cDME_GetLobby());
            Net_CleanupGame();
        }
    }
    if (!w->b1C5) cGameSystem_ShowEndMissionScreens(w, mode);
    cNetObj_Clear();
    had = false;
    if (cDME_GetLobby()) {
        had = true;
        cDME_StartUpdateThread();
    }
    {
        V3_134640* e = w->fE8;
        e->a = 0;
        e->b = 0;
        e->c = 0;
    }
    Clear_134640(&w->lC4);
    cTextSystem_Clear(GetTextSystem());
    cGOBJActivationMan_Clear(GetGOBJActivationMan());
    cGameSystem_RemoveVUMGOBJNames(w);
    cLoader_DeallocateAllAnimationBuffers(w->f88);
    cGameSystem_DestroyPlayerCameraAndScene(w);
    cWeaponDB_UnloadLevelSpecific(w->f1E0);
    cInventory_UnloadShapes();
    if (svc) cGameSound_Unload(svc);
    cScene_DeactivateAll(w->fD0);
    EventQueue_ClearAll();
    nGobjManager_RemoveAll();
    {
        void* p = w->f1F4;
        AllocGuard g;
        if (p) cBaseObjList_dtor(p, 0);
        cMemMan_Deallocate(0, p, D_0049A890, 0x34D);
    }
    {
        void* p = w->f1F8;
        AllocGuard g;
        if (p) cBaseObjList_dtor(p, 0);
        cMemMan_Deallocate(0, p, D_0049A890, 0x34E);
    }
    w->f1F4 = 0;
    w->f1F8 = 0;
    cParticleSystem_Clear(D_0053B540);
    cAI_SystemClear();
    {
        void* p = w->fDC;
        AllocGuard g;
        cHud_dtor(p, -1);
        cMemMan_Deallocate(0, p, D_0049A890, 0x35C);
    }
    w->fDC = 0;
    cGameSystem_DestroyAnimationSets(w);
    cGameSystem_DestroySkeletons(w);
    {
        VDel_134640* p = cSystemContainer_RemoveSystem(w, cSystemContainer_GetSystem(w, g_LosCheckService));
        AllocGuard g;
        p->Del(-1);
        cMemMan_Deallocate(0, p, D_0049A890, 0x366);
    }
    cCollisionSystem_cBox_UnInitStatics();
    nCollision_UnInitStatics();
    cHuman_UnInitStatics();
    cMotionManager_UnInitStatics();
    Destroy_134640();
    nCollision_UnInitStatics();
    cLightMan_DeallocateLightSources(g_LightMgr);
    nSfxLoader_UnloadEffects();
    cShadowMan_Purge(D_00543790);
    Monster_dtor(g_AgentPartCache, -1);
    SKLHog_DeleteIdentities();
    cFileStreamMan_Purge(GetFileStreamMan());
    cObjectiveMan_DestroyObjectives(cSystemContainer_GetSystem(w, D_004F7578));
    if (had) cDME_StopUpdateThread();
    g_IsMultiplayer = 0;
    D_005721B8 = 0;
    ClearMessages();
    EventQueue_ClearAll();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00134640(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00134640 */

/* merge_units: begin func_00134E00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_00134E00 { void* vt; char m4[0x10]; char m14[4]; };
extern "C" {
extern char D_004DA2F0[];
extern "C" void cCollisionModelList_dtor();
extern "C" void cCollisionModelList_GetList();
extern "C" void cCollisionModelList_SetCenterOfActivation();
extern "C" void cCollisionModelList_Prepare();
void * const D_004D9140[8] = { (void*)0x0, (void*)0x0, (void*)cCollisionModelList_dtor, (void*)cCollisionModelList_GetList, (void*)cCollisionModelList_SetCenterOfActivation, (void*)cCollisionModelList_Prepare, (void*)0x0, (void*)0x0 };
void cArray_FixedCapacity_cGOBJPtr_2_dtor(void* m, short f);
void cArray_cGOBJPtr_dtor(void* m, short f);
void operator_delete(void* p);
}
extern "C" O_00134E00* cCollisionModelList_Game_dtor(O_00134E00* self, short del)
{
    if (self) {
        self->vt = D_004DA2F0;
        if (self) {
            self->vt = ((char*)D_004D9140);
            cArray_FixedCapacity_cGOBJPtr_2_dtor(self->m14, -1);
            cArray_cGOBJPtr_dtor(self->m4, -1);
        }
        if (del > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00134E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00134E00 */
