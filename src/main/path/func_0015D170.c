#include "types.h"
extern void GObj_GetID();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void NpcRouteMgr_HandleMessage();
extern void Receiver_GetScriptTypeKey();
extern void Receiver_ScriptDispatch();
extern void * const D_004D96C0[];
extern void std_list_cPathSystemRequestPtr_dtor(void* p, int flag);
extern void Receiver_Destruct(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_D170;
S_D170* NpcRouteMgr_Destruct(S_D170* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)D_004D96C0);
        m = (char*)self + 0x2C;
        if (m)
            std_list_cPathSystemRequestPtr_dtor(m, 0);
        m = (char*)self + 0x20;
        if (m)
            std_list_cPathSystemRequestPtr_dtor(m, 0);
        Receiver_Destruct(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D96C0[16] = { (void*)0x0, (void*)0x0, (void*)NpcRouteMgr_Destruct, (void*)NpcRouteMgr_HandleMessage, (void*)GObj_GetID, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
