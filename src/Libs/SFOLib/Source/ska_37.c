/*
 * Libs/SFOLib/Source/ska: 1 file, 003B24C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B24C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

void* cQuaternion_opAdd_void(void* self) {
    return self;
}

int cSkaAnimDataFrame_ConstIterator_Quaternion(char* self) {
    return *(int*)(self + 0);
}

/* angular += rate * dt */
void cSkaAnimAnchor_AccumulateDeltaRot(SkaAnimRoot* root, float rate, float dt) {
    root->angular = root->angular + rate * dt;
}

int cSkaAnimDataFrame_ConstIterator_Scalar(char* self) {
    return *(int*)(self + 0);
}

/* Build an XYZ vector with W = 0 from the source's +8/+0xC/+0x10 floats. */
void cBoneData_PositionOffset(SkaVec4* out, SkaPoseSrc* src) {
    float z = src->z;
    float y = src->y;
    float x = src->x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 0;
}

int cBone_Properties(SkaAnimRoot* root) {
    return root->unkC0;
}
static inline void merge_flush_func_003B24C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B24C0 */
