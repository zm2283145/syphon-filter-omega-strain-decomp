/*
 * main/interface_model: range (3 files, 003F1860-003F1940)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "interface_model_types.h"

/* merge_units: begin func_003F1860 */
#pragma push /* merge_units */
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
extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* Clears the three vector words. */
OwnedVec* std_vector_imp_cKeyframe_tRGB_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

/* push_back: inserts one value at the end. */
int cArray_cAnimatorPtr_PushBackActual(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003F1940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003F1940 */
