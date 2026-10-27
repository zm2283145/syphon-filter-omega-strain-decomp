/*
 * SFOGame/Source/humanAnimData: 3 files, 00201E90-00201EF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201E90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_first_void(void* self) {
    return self;
}
static inline void merge_flush_func_00201E90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201E90 */

/* merge_units: begin func_00201EA0 */
#pragma push /* merge_units */
typedef struct { void* vtable; char kind; char pad[11]; Vec4 rot; } MotionNode;
extern char D_004DFC50[];
extern void cQuaternion_GetRotated(Vec4* out, Vec4* a, Vec4* b);
extern void cQuaternion_ctor_cQuaternionR(Vec4* dst, Vec4* src);

/* Base copy-constructor: sets the vtable, copies the kind byte and the composed rotation. */
MotionNode* cSkaNode_ctor_cSkaNodeR_cQuaternionR(MotionNode* self, MotionNode* src, Vec4* offset)
{
    Vec4 q;
    self->vtable = D_004DFC50;
    self->kind = src->kind;
    cQuaternion_GetRotated(&q, &src->rot, offset);
    cQuaternion_ctor_cQuaternionR(&self->rot, &q);
    return self;
}
static inline void merge_flush_func_00201EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201EA0 */

/* merge_units: begin func_00201EF0 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } Vec3;
typedef struct { float x, y, z, w; } Quat;
extern float COS(float);
extern float SIN(float);

Quat* cQuaternion_ctor_cEulerAngleTR(Quat* q, Vec3* e) {
    float hx = 0.5f * e->x;
    float hy = 0.5f * e->y;
    float hz = 0.5f * e->z;
    float cx = COS(hx);
    float cy = COS(hy);
    float cz = COS(hz);
    float sx = SIN(hx);
    float sy = SIN(hy);
    float sz = SIN(hz);
    float cycz = cy * cz;
    float sysz = sy * sz;
    float sycz = sy * cz;
    float cysz = cy * sz;
    q->w = cx * cycz - sx * sysz;
    q->x = sx * cycz - cx * sysz;
    q->y = cx * sycz + sx * cysz;
    q->z = cx * cysz + sx * sycz;
    return q;
}
static inline void merge_flush_func_00201EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201EF0 */
