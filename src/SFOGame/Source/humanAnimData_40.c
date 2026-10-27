/*
 * SFOGame/Source/humanAnimData: 3 files, 001F3E10-001F3EF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3E10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" void operator_delete(void* allocation);
extern "C" void cSkaBlendSequenceExtents_dtor(void* m, int flags);
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
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

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
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

#if 0 /* merge_units */
extern void* D_004DFBF0;
#endif /* merge_units */
#define D_004DFBF0 (*(void **)&D_004DFBF0) /* merge_units */

extern MotionNode* cSkaNode_ctor_eType_cQuaternionR(MotionNode*, int, int);
extern ObjVec* cArray_cSkaBlendSequenceItem_ctor_void(ObjVec*);
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray(int, ObjVec*);

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
static inline void merge_flush_func_001F3EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3EF0 */
