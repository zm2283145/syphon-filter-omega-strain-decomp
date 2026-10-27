#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct F1SEv { int owner; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; int* args; int count; int x14; int x18; } F1SEv;
extern "C" {
extern char D_004D9DE0[];
extern "C" void SchedCallback_dtor();
extern "C" void SchedCallback_Call();
extern "C" void cCBData_IsReferencing();
void * const D_004E00C0[8] = { (void*)0x0, (void*)0x0, (void*)SchedCallback_dtor, (void*)cCBData_IsReferencing, (void*)SchedCallback_Call, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char D_004BD4C0[];
void* cMemMan_Allocate(int, int, char*, int);
void* memcpy(void*, const void*, unsigned int);
}
static inline void* f1_AllocSE(int size, char* file, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, file, line);
}
extern "C" F1SEv* SchedCallback_ctor(F1SEv* self, int owner, int x14, int* args, int count, int x18)
{
    self->vt = D_004D9DE0;
    self->b4 = 1;
    self->owner = owner;
    self->b5 = 0;
    self->vt = ((char*)D_004E00C0);
    self->x14 = x14;
    self->count = count;
    self->x18 = x18;
    self->args = self->count ? (int*)f1_AllocSE(self->count * 4, D_004BD4C0, 0x729) : 0;
    memcpy(self->args, args, self->count * 4);
    return self;
}
