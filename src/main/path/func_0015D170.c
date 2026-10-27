#include "types.h"
extern void cSystem_ScriptGetObjectId();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void cPathSystem_HandleMessage();
extern void cSystem_getSOBJClassId();
extern void cSystem_ScriptHandleMessage();
extern void * const D_004D96C0[];
extern void std_list_cPathSystemRequestPtr_dtor(void* p, int flag);
extern void cSystem_dtor(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_D170;
S_D170* cPathSystem_dtor(S_D170* self, short flag)
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
        cSystem_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D96C0[16] = { (void*)0x0, (void*)0x0, (void*)cPathSystem_dtor, (void*)cPathSystem_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)0x0 };
