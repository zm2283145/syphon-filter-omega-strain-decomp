#include "types.h"
typedef struct { void* vt; char pad[0x28]; char sub[0x18]; char a44[0x108]; char a14C[0x12D]; char m279[4]; } S_96D0;
extern void GObj_GetID();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void Object_BroadcastToChildren();
extern void Receiver_GetScriptTypeKey();
extern void Receiver_ScriptDispatch();
extern void * const D_004D97B0[];
void cDME_dtor(void* p, int f);
void String_Dtor_138350(void* p, int f);
void __destroy_array(void* arr, void* dtor, int size, int n);
void ListReceiver_Dtor(S_96D0* p, int f);
void operator_delete(void* p);
S_96D0* App_dtor(S_96D0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004D97B0);
        cDME_dtor(self->m279, -1);
        if (self->sub) {
            __destroy_array(self->a14C, String_Dtor_138350, 0xC, 0x14);
            __destroy_array(self->a44, String_Dtor_138350, 0xC, 0x16);
        }
        ListReceiver_Dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D97B0[16] = { (void*)0x0, (void*)0x0, (void*)App_dtor, (void*)Object_BroadcastToChildren, (void*)GObj_GetID, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
