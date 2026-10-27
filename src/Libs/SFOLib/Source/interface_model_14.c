/*
 * Libs/SFOLib/Source/interface_model: 4 files, 003F1860-003F1980
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F1860 */
#pragma push /* merge_units */
#include "types.h"
#include "interface_model_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern OwnedVec* std_vector_imp_cKeyframe_float_ctor(OwnedVec* v);
extern int func_003F24A0(RawVec* v, char* pos, int n, int value);
extern int func_003F29B0(int a0, int a1);

/* push_back on a vector of 8-byte elements. */
int cArray_cKeyframe_float_PushBackActual(RawVec* v, int value) {
    return func_003F24A0(v, v->data + (v->count << 3), 1, value);
}

int cArray_cKeyframe_float_ReserveActual(int a0, int a1) {
    return func_003F29B0(a0, a1);
}

OwnedVec* cArray_cKeyframe_float_ctor(OwnedVec* v) {
    std_vector_imp_cKeyframe_float_ctor(v);
    v->unk0C = 1;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003F1860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003F1860 */

/* merge_units: begin func_003F18C0 */
#pragma push /* merge_units */
extern OwnedVec* std_vector_imp_cKeyframe_tRGB_ctor(OwnedVec* v);
extern int func_003F3370(RawVec* v, char* pos, int n, int value);
extern int func_003F3900(int a0, int a1);

/* Clears the three vector words. */
OwnedVec* std_vector_imp_cKeyframe_float_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

/* push_back on a vector of 16-byte elements. */
int cArray_cKeyframe_tRGB_PushBackActual(RawVec* v, int value) {
    return func_003F3370(v, v->data + (v->count << 4), 1, value);
}

int cArray_cKeyframe_tRGB_ReserveActual(int a0, int a1) {
    return func_003F3900(a0, a1);
}

OwnedVec* cArray_cKeyframe_tRGB_ctor(OwnedVec* v) {
    std_vector_imp_cKeyframe_tRGB_ctor(v);
    v->unk0C = 1;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003F18C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003F18C0 */

/* merge_units: begin func_003F1940 */
#pragma push /* merge_units */
extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* Clears the three vector words. */
OwnedVec* std_vector_imp_cKeyframe_tRGB_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

/* push_back: inserts one value at the end. */
int cArray_cAnimatorPtr_PushBackActual(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003F1940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003F1940 */

/* merge_units: begin func_003F1980 */
#pragma push /* merge_units */
typedef struct EVec { int unk0; int count; FloatVec3* data; char unk0C; } EVec;
typedef struct IfModelList {
    IfModelItem base;
    int unk18;
    int unk1C;
    EVec vec;
} IfModelList;
extern char D_004E0800[];
extern char D_004E07A0[];
extern EVec* std_vector_cKeyframe_cXyz_ctor(EVec* v);
extern void func_003F3150(EVec* v, int n);
extern FloatVec3* func_003F3DF0(FloatVec3* dst, float** cursor);
extern int func_003F2BC0(EVec* v, FloatVec3* pos, int n, FloatVec3* val);
IfModelList* cKeyframeAnimation_cXyz_ctor(IfModelList* self, int a, float** cursor)
{
    EVec* v;
    int n;
    int i;
    self->base.vtable = D_004E0800;
    self->base.unk04 = 0;
    self->base.unk08 = -1.0f;
    self->base.unk0C = -1.0f;
    self->base.unk10 = 0;
    self->base.unk14 = 0;
    self->base.vtable = D_004E07A0;
    self->unk18 = 0;
    self->unk1C = a;
    v = &self->vec;
    std_vector_cKeyframe_cXyz_ctor(v);
    v->unk0C = 1;
    n = *(int*)*cursor;
    *cursor = *cursor + 1;
    func_003F3150(v, n);
    for (i = 0; i < n; i++) {
        FloatVec3 tmp;
        func_003F3DF0(&tmp, cursor);
        func_003F2BC0(&self->vec, self->vec.data + self->vec.count, 1, &tmp);
    }
    return self;
}
static inline void merge_flush_func_003F1980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F1980 */
