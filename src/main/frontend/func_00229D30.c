#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "frontend.h"
extern "C" {
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cSystem_IsNetworked();
extern "C" void cSystemContainer_HandleMessage();
extern "C" void cSystem_getSOBJClassId();
extern "C" void cSystem_ScriptHandleMessage();
extern void * const FrontEndScene_vtable[];
extern char D_004A6308[]; /* "frontend.cc" */
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void CCI_Screen_ScreenCleanup(void* characters);
void cFrontendSystem_DestroySkeletons(FrontEndScene* self, void* archives);
void cMotionManager_UnInitStatics(void);
void cLList_cHogFile_dtor(void* p, int f);
void cSystemContainer_dtor(void* p, int f);
void operator_delete(void* p);
}
/* Deleting destructor (FrontEndScene_vtable slot 2). */
extern "C" FrontEndScene* cFrontendSystem_dtor(FrontEndScene* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)FrontEndScene_vtable);
        if (self->characters) {
            CCI_Screen_ScreenCleanup(self->characters);
            {
                void* p = self->characters;
                AllocGuard g;
                cMemMan_Deallocate(0, p, D_004A6308, 0x5C);
            }
            self->characters = 0;
        }
        cFrontendSystem_DestroySkeletons(self, self->archives);
        cMotionManager_UnInitStatics();
        if (self->archives)
            cLList_cHogFile_dtor(self->archives, -1);
        cSystemContainer_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const FrontEndScene_vtable[16] = { (void*)0x0, (void*)0x0, (void*)cFrontendSystem_dtor, (void*)cSystemContainer_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)0x0 };
