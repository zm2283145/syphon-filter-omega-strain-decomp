/*
 * SFOGame/Source/humanAnimData: 5 files, 001F2A00-001F2B70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F2A00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vtable_chain_dtor.h"
extern "C" void cSkaNode_PlaybackGroupId();
extern void * const D_004DFC50[];
extern "C" VtableChainObject* cSkaNode_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFC50);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFC50[8] = { (void*)0x0, (void*)0x0, (void*)cSkaNode_dtor, (void*)0x0, (void*)cSkaNode_PlaybackGroupId, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_001F2A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2A00 */

/* merge_units: begin func_001F2A50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "member0_dtor.h"
DEFINE_MEMBER0_DTOR(cArray_cSkaSwitchItem_dtor, std_vector_cSkaSwitchItem_dtor)
static inline void merge_flush_func_001F2A50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2A50 */

/* merge_units: begin func_001F2AB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"
DEFINE_DIRECT_BASE_DTOR(std_vector_cSkaSwitchItem_dtor, std_vector_imp_cSkaSwitchItem_dtor)
static inline void merge_flush_func_001F2AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2AB0 */

/* merge_units: begin func_001F2B10 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_DIRECT_BASE_DTOR(std_vector_imp_cSkaSwitchItem_dtor, std_vector_deleter_cSkaSwitchItem_dtor)
static inline void merge_flush_func_001F2B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2B10 */

/* merge_units: begin func_001F2B70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern void* D_004DFBB0;
extern MotionNode* cSkaNode_ctor_eType_cQuaternionR(MotionNode*, int, int);
extern void cSkaInitListOfPointers_cSkaSwitchItem_CopyPointerContentsToArray(int, ObjVec*);
extern ObjVec* cArray_cSkaSwitchItem_ctor_void(ObjVec*);

/* Constructor of the type-3 motion node (same layout as MotionSlider up to 0x34). */
MotionSlider* cSkaSwitch_ctor(MotionSlider* self, int a1, int a2, int a3) {
    cSkaNode_ctor_eType_cQuaternionR(&self->base, 3, a3);
    self->base.vtable = &D_004DFBB0;
    self->unk20 = a1;
    cArray_cSkaSwitchItem_ctor_void(&self->children);
    cSkaInitListOfPointers_cSkaSwitchItem_CopyPointerContentsToArray(a2, &self->children);
    return self;
}
static inline void merge_flush_func_001F2B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2B70 */
