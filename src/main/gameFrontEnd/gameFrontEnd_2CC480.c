/*
 * main/gameFrontEnd: range (4 files, 002CC480-002CC6D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_002CC480 */
#pragma push /* merge_units */
typedef struct { int size; char hdr[4]; void* first; } ListC520;
ListC520* std_list_MessageBoxEntry_dtor(ListC520* self, short deleteFlag); /* gsynth: defined below */
#pragma cplusplus on
extern "C" {
extern "C" void Event_PackHeader();
extern "C" void Message_GetScriptTypeKey();
extern "C" void GObj_GetID();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cNextFrameMsg_dtor();
extern "C" void cSystem_IsNetworked();
extern "C" void cNextFrameMsg_Clone();
extern "C" void SoundPauseMsg_dtor();
extern "C" void SoundPauseMsg_Clone();
extern "C" void FrontEnd_v01();
extern "C" void Receiver_GetScriptTypeKey();
extern "C" void Receiver_ScriptDispatch();
extern void * const D_004DE180[];
void FrontEnd_TeardownGui(void* self);
#if 0 /* merge_units */
void std_list_MessageBoxEntry_dtor(void* m, int flags);
#endif /* merge_units */
#define std_list_MessageBoxEntry_dtor(a0, a1) ((void)std_list_MessageBoxEntry_dtor((ListC520 *)(a0), (short)(a1))) /* merge_units */

void Receiver_Destruct(void* self, int flags);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}
struct ObjC480 { void* vtable; char pad[0x24]; unsigned char active; char pad2[0x2FC - 0x29]; char member[4]; };
extern "C" ObjC480* FrontEnd_dtor(ObjC480* self, short deleteFlag)
{
    if (self) {
        void* m;
        self->vtable = ((char*)D_004DE180);
        if (self->active)
            FrontEnd_TeardownGui(self);
        m = self->member;
        if (m)
            std_list_MessageBoxEntry_dtor(m, 0);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE180[32] = { (void*)0x0, (void*)0x0, (void*)FrontEnd_dtor, (void*)FrontEnd_v01, (void*)GObj_GetID, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0, (void*)0x0, (void*)0x0, (void*)cNextFrameMsg_dtor, (void*)cNextFrameMsg_Clone, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)SoundPauseMsg_dtor, (void*)SoundPauseMsg_Clone, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
#undef std_list_MessageBoxEntry_dtor /* merge_units */
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC480 */

/* merge_units: begin func_002CC520 */
#pragma push /* merge_units */
extern void std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(void** res, ListC520* l, void** first, void** last);
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

ListC520* std_list_MessageBoxEntry_dtor(ListC520* self, short deleteFlag)
{
    if (self) {
        if (self) {
            if (self) {
                void* res;
                void* first;
                void* last;
                last = self->hdr;
                first = self->first;
                std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(&res, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC520 */

/* merge_units: begin func_002CC5A0 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char p004[0x1C];
    long long t20;
    unsigned char b28, b29, b2A, b2B, b2C, b2D, b2E, b2F;
    unsigned char b30, b31, b32, b33, b34, b35, b36, b37;
    unsigned char b38;
    char names[8][32];
    char p139[3];
    int count13C;
    unsigned char b140;
    char p141[0x3F];
    int i180;
    unsigned char b184, b185;
    char p186[2];
    unsigned char b188;
    char p189[0x3F];
    unsigned char b1C8;
    char p1C9[0x7F];
    int i248, i24C;
    unsigned char b250;
    char p251[3];
    int i254, i258, i25C, i260;
    unsigned char b264, b265;
    char p266[2];
    int i268;
    char name26C[0x40];
    char name2AC[0x40];
    unsigned char b2EC;
    char p2ED[3];
    int i2F0, i2F4, i2F8;
    char list2FC[0xC];
    int i308, i30C;
    unsigned char b310;
} ObjC5A0;
extern char D_0051EE98[];
#if 0 /* merge_units */
extern char D_004DE180[];
#endif /* merge_units */
#define D_004DE180 ((char*)&D_004DE180) /* merge_units */

extern void Receiver_Construct(void* self, void* id);
extern void std_list_deleter_MessageBoxEntry_ctor(void* list);
extern void DME_CreateLobby(void);
extern void DME_SetLobbyActive(int a);
ObjC5A0* FrontEnd_ctor(ObjC5A0* o)
{
    Receiver_Construct(o, D_0051EE98);
    o->vtable = D_004DE180;
    o->i180 = 4;
    o->b184 = 0;
    o->b185 = 0;
    o->b140 = 0;
    o->b188 = 0;
    o->b1C8 = 0;
    o->i248 = -1;
    o->i24C = -1;
    o->b250 = 0;
    std_list_deleter_MessageBoxEntry_ctor(o->list2FC);
    o->t20 = 0;
    o->b28 = 0;
    o->b29 = 0;
    o->b2B = 0;
    o->b2C = 0;
    o->b310 = 0;
    o->b2D = 0;
    o->b2F = 0;
    o->b30 = 0;
    o->b32 = 0;
    o->b33 = 0;
    o->b34 = 0;
    o->b31 = 0;
    o->b36 = 0;
    o->b35 = 0;
    o->i260 = 0;
    o->i25C = 0;
    o->i30C = -1;
    o->i308 = 0;
    o->b264 = 0;
    o->b265 = 0;
    o->i268 = 0;
    o->b2EC = 0;
    o->i2F0 = 0;
    o->i2F4 = 0;
    o->i2F8 = 0;
    o->b2E = 0;
    o->i258 = 0;
    o->b37 = 0;
    o->names[0][0] = 0;
    o->names[1][0] = 0;
    o->names[2][0] = 0;
    o->names[3][0] = 0;
    o->names[4][0] = 0;
    o->names[5][0] = 0;
    o->names[6][0] = 0;
    o->names[7][0] = 0;
    o->count13C = 0;
    DME_CreateLobby();
    DME_SetLobbyActive(0);
    o->name2AC[0] = 0;
    o->name26C[0] = 0;
    o->i254 = 4;
    return o;
}
#undef D_004DE180 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC5A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC5A0 */

/* merge_units: begin func_002CC6D0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_MessageBoxEntry_dtor, std_list_imp_MessageBoxEntry_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002CC6D0 */
