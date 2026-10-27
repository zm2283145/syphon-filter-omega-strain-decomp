/*
 * SFOGame/Source/humanIk: 2 files, 001D28D0-001D29E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D28D0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { float x, y, z, w; } Vec16;
typedef struct { char pad[0x10]; char inner[0xC0]; char out[0x30]; } Slot1D2;
typedef struct { char pad[0x1C0]; Vec16 pos; } Elem1D0;
typedef struct { char pad[0x20]; Elem1D0* elems; } Table1D2;
typedef struct { int unk0; Table1D2* table; } Obj1D2;

extern Slot1D2 UpperBodyNodeTable[];
extern void cQuaternion_ctor_void(Vec16* v);
extern void* cQuaternion_opAssign(Vec16* v, void* src);
extern void* cJointInfo_BoneSpaceToJointSpaceTransform(void* inner);
extern void cQuaternion_Rotate(void* dst, void* m);
extern void nIk_NegateIfDotProductNegative(Vec16* a, Vec16* b);
extern void* func_001D2870(void* inner);
extern void nIk_ApplyJointLimits(void* out, Vec16* v, void* m);
#if 0 /* merge_units */
extern void* cJointInfo_JointSpaceToBoneSpaceTransform(void* inner);
#endif /* merge_units */
void * cJointInfo_JointSpaceToBoneSpaceTransform(); /* merge_units */

extern void cBoneIk_LimbPose_CalculateSkelSpaceInfo(Slot1D2* slot);

/* Transforms a point and the indexed element's position through slot idx and updates the slot. */
void cHumanIkRoutine_OrientHand(Obj1D2* self, void* point, int idx)
{
    Vec16 b;
    Vec16 a;
    void* out;
    Slot1D2* slot;
    Vec16* pos;
    void* r;
    slot = &UpperBodyNodeTable[idx];
    out = slot->out;
    pos = &self->table->elems[idx].pos;
    cQuaternion_ctor_void(&a);
    r = cQuaternion_opAssign(&a, point);
    cQuaternion_Rotate(r, cJointInfo_BoneSpaceToJointSpaceTransform(slot->inner));
    cQuaternion_ctor_void(&b);
    r = cQuaternion_opAssign(&b, pos);
    cQuaternion_Rotate(r, cJointInfo_BoneSpaceToJointSpaceTransform(slot->inner));
    nIk_NegateIfDotProductNegative(&a, &b);
    nIk_ApplyJointLimits(out, &a, func_001D2870(slot->inner));
    cQuaternion_Rotate(out, cJointInfo_JointSpaceToBoneSpaceTransform(slot->inner));
    cBoneIk_LimbPose_CalculateSkelSpaceInfo(slot);
}
static inline void merge_flush_func_001D28D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D28D0 */

/* merge_units: begin func_001D29E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cJointInfo_JointSpaceToBoneSpaceTransform(char* self) {
    return self + 16;
}
static inline void merge_flush_func_001D29E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D29E0 */
