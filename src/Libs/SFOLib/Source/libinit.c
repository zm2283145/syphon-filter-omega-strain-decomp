/*
 * Libs/SFOLib/Source/libinit: 7 files, 003A6120-003A6320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A6120 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_chain_dtor.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cSplineDefinition_dtor, D_004DFB70, D_004DFAA0)
static inline void merge_flush_func_003A6120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6120 */

/* merge_units: begin func_003A6180 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cSprayDefinition_dtor, D_004DFB90, D_004DFAA0)
static inline void merge_flush_func_003A6180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6180 */

/* merge_units: begin func_003A61E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(std_list_cParticleDefinitionPtr_dtor, std_vector_deleter_cArray_int_dtor)
static inline void merge_flush_func_003A61E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A61E0 */

/* merge_units: begin func_003A6240 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: destroy the member at +4, then delete. */
extern "C" void operator_delete(void* allocation);
extern "C" void* std_list_cParticleDefinitionPtr_dtor(void* self, short deleteFlag);

typedef struct { int pad0; int member; } Obj_3A6240;

extern "C" Obj_3A6240* cParticleSystem_dtor(Obj_3A6240* self, short deleteFlag)
{
    if (self) {
        void* m = &self->member;
        if (m)
            std_list_cParticleDefinitionPtr_dtor(m, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003A6240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6240 */

/* merge_units: begin func_003A62A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cSkeletonDataBankEntryPtr_dtor)
static inline void merge_flush_func_003A62A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A62A0 */

/* merge_units: begin func_003A6320 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: own cleanup, then the base destructor. */

extern "C" void cSkeletonDataBank_Clear(void* self);
#if 0 /* merge_units */
extern "C" void* std_list_cSkeletonDataBankEntryPtr_dtor(void* self, short deleteFlag);
#endif /* merge_units */
#define std_list_cSkeletonDataBankEntryPtr_dtor(a0, a1) ((void *)std_list_cSkeletonDataBankEntryPtr_dtor((ObjList *)(a0), (a1))) /* merge_units */


extern "C" void* cSkeletonDataBank_dtor(void* self, short deleteFlag)
{
    if (self) {
        cSkeletonDataBank_Clear(self);
        if (self)
            std_list_cSkeletonDataBankEntryPtr_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef std_list_cSkeletonDataBankEntryPtr_dtor /* merge_units */
static inline void merge_flush_func_003A6320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6320 */

/* merge_units: begin func_003A6390 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int CreateSema(char *);
int CreateThread(char *);
int StartThread(int, int);
int GetThreadId();
int sceSifSearchModuleByName(char *);
int sceCdPOffCallback(char *, int);
extern int D_004934C8;
extern int D_004934D0;
extern int D_004934D8;
extern char D_0053BBC0;
extern char func_003A6450;
extern char SFOPowerOffThread;

void SFOPreparePowerOff(void) {
    struct { int f10; int f14; int f18[3]; int f24[3]; int f30; char * f34; char * f38; int f3C; int f40; int f44[7]; } sl;

    if (sceSifSearchModuleByName("dev9") >= 0) {
        sl.f14 = 1;
        sl.f18[0] = 0;
        sl.f24[0] = 0;
        D_004934D8 = CreateSema(&sl.f10);
        D_004934C8 = GetThreadId();
        sl.f40 = 0;
        sl.f3C = 0x2000;
        sl.f34 = &SFOPowerOffThread;
        sl.f38 = &D_0053BBC0;
        sl.f44[0] = 1;
        D_004934D0 = CreateThread(&sl.f30);
        StartThread(D_004934D0, D_004934D8);
        sceCdPOffCallback(&func_003A6450, D_004934D8);
    }
}
static inline void merge_flush_func_003A6390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6390 */
