/*
 * SFOGame/Source/humanAnimData: 11 files, 001F3BB0-001F3F80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3BB0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Obj3 {
    int base;
    int unk4;
    int unk8;
} Obj3;

#if 0 /* merge_units */
extern void compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(Obj3* self, int arg);
#endif /* merge_units */
Word * compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(); /* merge_units */



/* Constructor: base init with 0, then clears the two following words. */
Obj3* std_vector_deleter_cSkaBlendSequenceItem_ctor_void(Obj3* self) {
    compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(self, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
static inline void merge_flush_func_001F3BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3BB0 */

/* merge_units: begin func_001F3BF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_uint(Word*, int);
#if 0 /* merge_units */
extern Word* cAllocator_cSkaBlendSequenceItem_ctor_void(Word*);
#endif /* merge_units */
void * cAllocator_cSkaBlendSequenceItem_ctor_void(); /* merge_units */



Word* compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(Word* self, int value) {
    details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_uint(self, value);
    return self;
}

Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_uint(Word* self, int value) {
    cAllocator_cSkaBlendSequenceItem_ctor_void(self);
    self->value = value;
    return self;
}
static inline void merge_flush_func_001F3BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3BF0 */

/* merge_units: begin func_001F3C60 */
#pragma push /* merge_units */
void* cAllocator_cSkaBlendSequenceItem_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_001F3C60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3C60 */

/* merge_units: begin func_001F3C70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor, cLList_cSkaBlendSequenceItemPtr_dtor)
#pragma optimization_level reset
static inline void merge_flush_func_001F3C70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3C70 */

/* merge_units: begin func_001F3CE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor (built at -O1). */
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cLList_cSkaBlendSequenceItemPtr_dtor, std_list_cSkaBlendSequenceItemPtr_dtor)
#pragma optimization_level reset
static inline void merge_flush_func_001F3CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3CE0 */

/* merge_units: begin func_001F3D50 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor (built at -O1). */
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(std_list_cSkaBlendSequenceItemPtr_dtor, func_00135C90)
#pragma optimization_level reset
static inline void merge_flush_func_001F3D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3D50 */

/* merge_units: begin func_001F3DC0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkaBlendSequenceExtents_dtor)
static inline void merge_flush_func_001F3DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3DC0 */

/* merge_units: begin func_001F3E10 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
#if 0 /* merge_units */
extern "C" void cSkaBlendSequenceExtents_dtor(void* m, int flags);
#endif /* merge_units */
#define cSkaBlendSequenceExtents_dtor(a0, a1) ((void)cSkaBlendSequenceExtents_dtor((a0), (short)(a1))) /* merge_units */

extern "C" void cPointer_cSkaNode_dtor(void* m, int flags);
extern "C" void* cSkaBlendSequenceItem_dtor(void* self, short deleteFlag)
{
    if (self) {
        cSkaBlendSequenceExtents_dtor((char*)self + 4, -1);
        cPointer_cSkaNode_dtor(self, -1);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef cSkaBlendSequenceExtents_dtor /* merge_units */
static inline void merge_flush_func_001F3E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3E10 */

/* merge_units: begin func_001F3E80 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x20]; char x24[1]; } MS1F3E80;
extern void cSkaSlider_UpdateNodes();
extern void cSkaNode_PlaybackGroupId();
extern void * const D_004DFBF0[];
extern void cArray_cSkaBlendSequenceItem_dtor(void*, int);
extern void cSkaNode_dtor(void*, int);
#if 0 /* merge_units */
extern void operator_delete(void*);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */


MS1F3E80* cSkaSlider_dtor(MS1F3E80* self, short flag) {
    if (self) {
        self->vt = ((char*)D_004DFBF0);
        cArray_cSkaBlendSequenceItem_dtor(self->x24, -1);
        cSkaNode_dtor(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DFBF0[8] = { (void*)0x0, (void*)0x0, (void*)cSkaSlider_dtor, (void*)cSkaSlider_UpdateNodes, (void*)cSkaNode_PlaybackGroupId, (void*)0x0, (void*)0x0, (void*)0x0 };
#undef operator_delete /* merge_units */
static inline void merge_flush_func_001F3E80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3E80 */

/* merge_units: begin func_001F3EF0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* D_004DFBF0;
#endif /* merge_units */
#define D_004DFBF0 (*(void **)&D_004DFBF0) /* merge_units */


extern MotionNode* cSkaNode_ctor_eType_cQuaternionR(MotionNode*, int, int);
extern ObjVec* cArray_cSkaBlendSequenceItem_ctor_void(ObjVec*);
#if 0 /* merge_units */
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray(int, ObjVec*);
#endif /* merge_units */
void cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray(void* src, void* dst); /* merge_units */
#define cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray(a0, a1) (cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray((void *)(a0), (void *)(a1))) /* merge_units */


MotionSlider* cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(MotionSlider* self, int a1, int a2, int a3, int t0, int t1) {
    cSkaNode_ctor_eType_cQuaternionR(&self->base, 2, t1);
    self->base.vtable = &D_004DFBF0;
    self->unk20 = a1;
    cArray_cSkaBlendSequenceItem_ctor_void(&self->children);
    self->unk34 = a3;
    self->unk35 = t0;
    cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray(a2, &self->children);
    return self;
}
#undef D_004DFBF0 /* merge_units */
#undef cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray /* merge_units */
static inline void merge_flush_func_001F3EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3EF0 */

/* merge_units: begin func_001F3F80 */
#pragma push /* merge_units */
#include "ptr_copy_loop.h"
#pragma opt_rotateloops off
DEFINE_PTR_COPY_LOOP(cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray, cLList_cSkaBlendSequenceItemPtr_Size, cArray_cSkaBlendSequenceItem_ReserveActual, cArray_cSkaBlendSequenceItem_Clear, cLList_cSkaBlendSequenceItemPtr_Begin, cLList_cSkaBlendSequenceItemPtr_End, cConstLListIterator_cSkaBlendSequenceItemPtr_opMul, cArray_cSkaBlendSequenceItem_PushBackActual, cConstLListIterator_cSkaBlendSequenceItemPtr_opInc, opNe_cConstLListIteratorR_cConstLListIteratorR_4)
#pragma opt_rotateloops reset
static inline void merge_flush_func_001F3F80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3F80 */
