/*
 * Libs/SFOLib/Source/libinit: 5 files, 003A6120-003A61E0
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
