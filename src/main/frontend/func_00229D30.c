#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "frontend.h"
extern "C" {
extern "C" void GObj_GetID();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_001383D0();
extern "C" void Object_BroadcastToChildren();
extern "C" void Receiver_GetScriptTypeKey();
extern "C" void Receiver_ScriptDispatch();
extern void * const FrontEndScene_vtable[];
extern char D_004A6308[]; /* "frontend.cc" */
void Mem_Free(int pool, void* p, char* file, int line);
void func_00229EB0(void* characters);
void FrontEndScene_UnloadSkeletons(FrontEndScene* self, void* archives);
void MotionManager_Shutdown(void);
void func_00137670(void* p, int f);
void ListReceiver_Dtor(void* p, int f);
void operator_delete(void* p);
}
/* Deleting destructor (FrontEndScene_vtable slot 2). */
extern "C" FrontEndScene* FrontEndScene_dtor(FrontEndScene* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)FrontEndScene_vtable);
        if (self->characters) {
            func_00229EB0(self->characters);
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
            func_00137670(self->archives, -1);
        ListReceiver_Dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const FrontEndScene_vtable[16] = { (void*)0x0, (void*)0x0, (void*)FrontEndScene_dtor, (void*)Object_BroadcastToChildren, (void*)GObj_GetID, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
