/*
 * main/game: range (2 files, 00137920-001379A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop

/* merge_units: begin func_00137920 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cEnvSettingsPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00137920 */

/* merge_units: begin func_001379A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_001379A0 { void* vt; char pad[0x24]; char m[4]; };
extern "C" {
extern "C" void GObj_GetID();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cSystem_IsNetworked();
extern "C" void HotboxTracker_HandleMessage();
extern "C" void Receiver_GetScriptTypeKey();
extern "C" void Receiver_ScriptDispatch();
extern void * const D_004D9960[];
void std_list_cHotboxPtr_dtor(void* m, short f);
void Receiver_Destruct(void* p, short f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

}
extern "C" O_001379A0* HotboxTracker_dtor(O_001379A0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004D9960);
        if (self->m) std_list_cHotboxPtr_dtor(self->m, 0);
        Receiver_Destruct(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004D9960[16] = { (void*)0x0, (void*)0x0, (void*)HotboxTracker_dtor, (void*)HotboxTracker_HandleMessage, (void*)GObj_GetID, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001379A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001379A0 */
