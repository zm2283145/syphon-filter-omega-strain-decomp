#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "frontend.h"
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
extern "C" void Object_BroadcastToChildren();
extern "C" void Receiver_GetScriptTypeKey();
extern "C" void Receiver_ScriptDispatch();
extern void * const FrontEndScene_vtable[];
extern char D_004A6308[]; /* "frontend.cc" */
void Mem_Free(int pool, void* p, char* file, int line);
void CCI_Screen_ScreenCleanup(void* characters);
void FrontEndScene_UnloadSkeletons(FrontEndScene* self, void* archives);
void MotionManager_Shutdown(void);
void cLList_cHogFile_dtor(void* p, int f);
void ListReceiver_Dtor(void* p, int f);
void operator_delete(void* p);
}
/* Deleting destructor (FrontEndScene_vtable slot 2). */
extern "C" FrontEndScene* FrontEndScene_dtor(FrontEndScene* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)FrontEndScene_vtable);
        if (self->characters) {
            CCI_Screen_ScreenCleanup(self->characters);
            {
                void* p = self->characters;
                AllocGuard g;
                Mem_Free(0, p, D_004A6308, 0x5C);
            }
            self->characters = 0;
        }
        FrontEndScene_UnloadSkeletons(self, self->archives);
        MotionManager_Shutdown();
        if (self->archives)
            cLList_cHogFile_dtor(self->archives, -1);
        ListReceiver_Dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const FrontEndScene_vtable[16] = { (void*)0x0, (void*)0x0, (void*)FrontEndScene_dtor, (void*)Object_BroadcastToChildren, (void*)GObj_GetID, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
