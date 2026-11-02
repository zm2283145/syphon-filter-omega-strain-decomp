/*
 * SFOGame/Source/gameCamera: 4 files, 0017EE30-0017EF30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017EE30 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_chain_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(func_0017EE30, D_004DA350)
static inline void merge_flush_func_0017EE30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017EE30 */

/* merge_units: begin func_0017EE80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" char D_004DAD70[];
extern "C" void cCollisionRoutine_cBox_dtor_void_2();
void * const D_004DA330[8] = { (void*)0x0, (void*)0x0, (void*)cCollisionRoutine_cBox_dtor_void_2, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
extern "C" VtableChainObject* cSplinedMotion_QuaternionLERP_1_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = D_004DAD70;
        if (self)
            self->vtable = ((char*)D_004DA330);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017EE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017EE80 */

/* merge_units: begin func_0017EEE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cCollisionSystem_cBox_dtor_void_2)
static inline void merge_flush_func_0017EEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017EEE0 */

/* merge_units: begin func_0017EF30 */
#pragma push /* merge_units */
extern char D_004DAD90[];
#if 0 /* merge_units */
extern char D_004DA330[];
#endif /* merge_units */
#define D_004DA330 ((char*)&D_004DA330) /* merge_units */

extern void std_vector_deleter_cVector_dtor(void* p, int f);
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

typedef struct { void* vt; } V_EF30;
V_EF30* cGameCameraCollisionRoutine_dtor(V_EF30* self, short flag)
{
    if (self) {
        void* m;
        self->vt = D_004DAD90;
        m = (char*)self + 0x30;
        if (m) {
            if (m) {
                if (m)
                    std_vector_deleter_cVector_dtor(m, 0);
            }
        }
        if (self)
            self->vt = D_004DA330;
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#undef D_004DA330 /* merge_units */
#undef operator_delete /* merge_units */
static inline void merge_flush_func_0017EF30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017EF30 */
