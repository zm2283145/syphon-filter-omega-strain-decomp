#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "frontend.h"
extern "C" {
extern "C" void func_0012ECE0();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_001383D0();
extern "C" void Object_BroadcastToChildren();
extern "C" void func_003CB1E0();
extern "C" void func_003CB1F0();
extern void * const FrontEndScene_vtable[];
extern char D_004A6308[]; /* "frontend.cc" */
void Mem_Free(int pool, void* p, char* file, int line);
void func_00229EB0(void* characters);
void FrontEndScene_UnloadSkeletons(FrontEndScene* self, void* archives);
void func_0040F570(void);
void func_00137670(void* p, int f);
void func_003CAD70(void* p, int f);
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
        func_0040F570();
        if (self->archives)
            func_00137670(self->archives, -1);
        func_003CAD70(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const FrontEndScene_vtable[16] = { (void*)0x0, (void*)0x0, (void*)FrontEndScene_dtor, (void*)Object_BroadcastToChildren, (void*)func_0012ECE0, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)func_003CB1E0, (void*)func_003CB1F0, (void*)0x0 };
