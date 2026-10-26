/*
 * main/frontCharacter: 2 files, 0022A770-0022A7B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022A770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_18(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0022A770 */

/* merge_units: begin func_0022A7B0 */
#pragma push /* merge_units */
extern void GObj_GetID();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void TargetVis_HandleResult();
extern void Receiver_GetScriptTypeKey();
extern void Receiver_ScriptDispatch();
extern void * const D_004DB850[];
extern void std_list_cSafePtr_cGOBJ_dtor(void* p, int flag);
extern void std_list_LosReqElem_dtor(void* p, int flag);
extern void Receiver_Destruct(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_D170;
S_D170* TargetVisMgr_dtor(S_D170* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)D_004DB850);
        m = (char*)self + 0x11C;
        if (m)
            std_list_cSafePtr_cGOBJ_dtor(m, 0);
        m = (char*)self + 0x110;
        if (m)
            std_list_LosReqElem_dtor(m, 0);
        Receiver_Destruct(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DB850[16] = { (void*)0x0, (void*)0x0, (void*)TargetVisMgr_dtor, (void*)TargetVis_HandleResult, (void*)GObj_GetID, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_0022A7B0 */
