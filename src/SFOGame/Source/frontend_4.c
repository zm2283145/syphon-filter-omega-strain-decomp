/*
 * SFOGame/Source/frontend: 2 files, 00229D30-00229E60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00229D30 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00229D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00229D30 */

/* merge_units: begin func_00229E60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

#if 0 /* merge_units */
extern void* D_004DB810;
#endif /* merge_units */
#define D_004DB810 (*(void **)&D_004DB810) /* merge_units */

extern int std_list_deleter_cHogFile_ctor(int*);
extern int cSystemContainer_ctor_void(Unk229E60*);
extern int cMotionManager_InitStatics(void);

Unk229E60* cFrontendSystem_ctor(Unk229E60* self) {
    cSystemContainer_ctor_void(self);
    self->vtable = &D_004DB810;
    std_list_deleter_cHogFile_ctor(&self->unk2C);
    cMotionManager_InitStatics();
    return self;
}
#undef D_004DB810 /* merge_units */
static inline void merge_flush_func_00229E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00229E60 */
