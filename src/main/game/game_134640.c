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
int Mem_Free();

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
extern char D_004EA0B0[];
extern VDel_134640* D_004EA0B8;
extern char D_004F2CC0[];
extern char D_004F7578[];
extern char D_00535D20[];
extern int D_0053B350;
extern int D_0053B358;
extern char D_0053B540[];
extern char D_0053BB90[];
extern char D_00543790[];
extern char D_00555070[];
extern char D_0055DDA0[];
extern unsigned char D_005721B8;
extern unsigned char D_005721C8;
extern unsigned char D_005721D8;
extern unsigned char D_005723B0;
extern char g_TargetVisMgr[];
void* ActivationMgr_Get(void);
void EventQueue_ClearAll(void);
void IdMgr_Destroy(void);
void LightMgr_FreePools(void* p);
void MsgQueue_ClearPending(void);
void NetSession_Cleanup(void);
void ObjMan_DeleteAll(void* p);
void* ObjMan_GetService(void);
void ObjectList_EraseRange(void* result, void* list, void* first, void* last);
void ScreenFx_Start(void* p, int a, float r, float g, float b, float c);
void Script_Cleanup(void* p);
void* Service_Lookup(void* a, void* b);
void TeamRelations_Teardown(void);
void WaterFx_Clear(void* p);
void WeaponDb_LoadResources(void* p);
void func_00130950(World_134640* w);
void func_001309A0(World_134640* w);
void func_00130B10(World_134640* w);
void func_00132A40(World_134640* w);
void LevelEnd_RunDebrief(World_134640* w, int mode);
void func_00135020(void);
void func_00136BD0(World_134640* w);
void func_00136CD0(World_134640* w);
void func_0013E070(void* p);
void func_0016F4D0(void);
void func_00170570(void);
void func_00170D30(void* p);
void func_001784B0(void* p);
void func_001AF7A0(void);
void func_001C3B00(void* p);
void func_001C9680(void* p);
void SoundMgr_UnloadLevel(void* p);
void func_00224140(void* p);
void func_002261C0(void* p);
void func_0022D3C0(void* p);
void func_00236F80(void);
void func_00238F20(void);
void func_002458E0(void* p, int f);
void func_002569C0(void);
void func_00257150(void);
void VisionFx_Prepare(void* p);
void VisionMgr_SetPendingMode(void* p, int a, int b);
void func_002683F0(void);
void PadRumble_Stop(void);
void Pad_EnableVibration(int a);
void TremorList_Free(void* p, int f);
void func_00275550(void);
void func_00279D80(void* p, int f);
void func_003A3670(void* p);
void func_003C2A80(void);
VDel_134640* func_003CAB50(World_134640* w, void* s);
void func_003D0FB0(void* p);
void* TextManager_Get(void);
void func_003D5750(void* p);
void func_003E56F0(void);
void FStream_CancelRequests(void* p);
void* Fstream_GetLoader(void);
void EffectService_ReleaseAll(void);
void func_003FDBB0(void);
void func_00404FD0(void* p, int a);
void func_00407BE0(void);
void func_00408EA0(void* p);
void GobjScopeBase_Dtor(void* p, int f);
void MotionManager_Shutdown(void);
void* DME_GetLobby(void);
void DME_StopThread(void);
void DME_StartThread(void);
void Net_CleanupGame(void);
void func_0042B2D0(void);
void func_0042E6D0(void);
void func_0044E340(void* p);
void ItemTable_GetModel(void);
}

static inline void Clear_134640(List_134640* l)
{
    int r;
    void* first;
    void* last;
    last = l->head;
    first = l->first;
    ObjectList_EraseRange(&r, l, &first, &last);
}

static inline void Destroy_134640(void)
{
    if (D_004EA0B8) {
        {
            VDel_134640* p = D_004EA0B8;
            AllocGuard g;
            p->Del(-1);
            Mem_Free(0, p, D_0049AEA0, 0xB9);
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

extern "C" void World_Teardown(World_134640* w)
{
    void* svc;
    int mode;
    bool had;
    func_002569C0();
    svc = Service_Lookup(w, D_004F2CC0);
    if (svc) func_001C9680(svc);
    {
        void* om = ObjMan_GetService();
        if (om) func_002261C0(om);
    }
    {
        void* p = w->fEC;
        AllocGuard g;
        func_00279D80(p, -1);
        Mem_Free(0, p, D_0049A890, 0x2CF);
    }
    w->fEC = 0;
    PadRumble_Stop();
    Pad_EnableVibration(0);
    {
        void* p = w->f8C;
        AllocGuard g;
        TremorList_Free(p, -1);
        Mem_Free(0, p, D_0049A890, 0x2D3);
    }
    w->f8C = 0;
    VisionMgr_SetPendingMode(w->fE0, 0, 1);
    ScreenFx_Start(w->fE0, 0, 0.0f, 0.0f, 0.0f, 0.0f);
    VisionFx_Prepare(w->fE0);
    WaterFx_Clear(w->fE4);
    D_0053B350 = 0;
    D_0053B358 = 0;
    func_00275550();
    func_00238F20();
    Script_Cleanup(D_00555070);
    func_002683F0();
    TeamRelations_Teardown();
    func_003FDBB0();
    func_00136BD0(w);
    func_001784B0(w->f84);
    Clear_134640(&w->l9C);
    func_00170D30(w->f80);
    func_00170570();
    func_0022D3C0(g_TargetVisMgr);
    func_00408EA0(D_0053BB90);
    EffectService_ReleaseAll();
    func_00136CD0(w);
    func_00257150();
    mode = 0;
    if (D_005721C8) {
        if (TakeFlag_134640()) {
            if (D_005723B0 == 1) mode = 1;
            else if (D_005723B0 == 2) mode = 2;
        }
        func_0042E6D0();
        func_003E56F0();
        func_0042B2D0();
        if (!w->b1C7) {
            if (DME_GetLobby()) func_0044E340(DME_GetLobby());
            Net_CleanupGame();
        }
    }
    if (!w->b1C5) LevelEnd_RunDebrief(w, mode);
    NetSession_Cleanup();
    had = false;
    if (DME_GetLobby()) {
        had = true;
        DME_StartThread();
    }
    {
        V3_134640* e = w->fE8;
        e->a = 0;
        e->b = 0;
        e->c = 0;
    }
    Clear_134640(&w->lC4);
    func_003D0FB0(TextManager_Get());
    func_00224140(ActivationMgr_Get());
    func_00130B10(w);
    func_001C3B00(w->f88);
    func_00132A40(w);
    WeaponDb_LoadResources(w->f1E0);
    ItemTable_GetModel();
    if (svc) SoundMgr_UnloadLevel(svc);
    func_0013E070(w->fD0);
    EventQueue_ClearAll();
    IdMgr_Destroy();
    {
        void* p = w->f1F4;
        AllocGuard g;
        if (p) GobjScopeBase_Dtor(p, 0);
        Mem_Free(0, p, D_0049A890, 0x34D);
    }
    {
        void* p = w->f1F8;
        AllocGuard g;
        if (p) GobjScopeBase_Dtor(p, 0);
        Mem_Free(0, p, D_0049A890, 0x34E);
    }
    w->f1F4 = 0;
    w->f1F8 = 0;
    func_003A3670(D_0053B540);
    func_0016F4D0();
    {
        void* p = w->fDC;
        AllocGuard g;
        func_002458E0(p, -1);
        Mem_Free(0, p, D_0049A890, 0x35C);
    }
    w->fDC = 0;
    func_001309A0(w);
    func_00130950(w);
    {
        VDel_134640* p = func_003CAB50(w, Service_Lookup(w, D_004EA0B0));
        AllocGuard g;
        p->Del(-1);
        Mem_Free(0, p, D_0049A890, 0x366);
    }
    func_00135020();
    func_003C2A80();
    func_001AF7A0();
    MotionManager_Shutdown();
    Destroy_134640();
    func_003C2A80();
    LightMgr_FreePools(D_00535D20);
    func_00236F80();
    func_003D5750(D_00543790);
    func_00404FD0(D_0055DDA0, -1);
    func_00407BE0();
    FStream_CancelRequests(Fstream_GetLoader());
    ObjMan_DeleteAll(Service_Lookup(w, D_004F7578));
    if (had) DME_StopThread();
    D_005721C8 = 0;
    D_005721B8 = 0;
    MsgQueue_ClearPending();
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
extern "C" void func_00136350();
extern "C" void func_00138580();
extern "C" void func_00138590();
extern "C" void func_001385A0();
void * const D_004D9140[8] = { (void*)0x0, (void*)0x0, (void*)func_00136350, (void*)func_00138580, (void*)func_00138590, (void*)func_001385A0, (void*)0x0, (void*)0x0 };
void func_00134FD0(void* m, short f);
void func_00134E80(void* m, short f);
void operator_delete(void* p);
}
extern "C" O_00134E00* func_00134E00(O_00134E00* self, short del)
{
    if (self) {
        self->vt = D_004DA2F0;
        if (self) {
            self->vt = ((char*)D_004D9140);
            func_00134FD0(self->m14, -1);
            func_00134E80(self->m4, -1);
        }
        if (del > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00134E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00134E00 */
