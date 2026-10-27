/*
 * main/game: 2 files, 00139AC0-00139B00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00139AC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00139AC0 */

/* merge_units: begin func_00139B00 */
#pragma push /* merge_units */
typedef struct Shape139 {
    Q rows[4];               /* 0x00 */
    char part40[0x10];       /* 0x40 (bytes 0x40, 0x42 cleared first) */
    unsigned char flag50;    /* 0x50 */
    unsigned char flag51;    /* 0x51 */
    unsigned char flag52;    /* 0x52 */
    char pad53[0xD];
    int part60[2];           /* 0x60 */
} Shape139;

extern void cVector_opAssign(Q* dst, Q* src);
extern void cCollisionModel_FaceProperties_opAssign(void* dst, void* src);
extern void cCollisionModel_FaceLocator_opAssign(void* dst, void* src);

/* Copy-assigns a shape; returns dst. */
Shape139* cCollisionFace_ctor_cCollisionFaceR(Shape139* dst, Shape139* src) {
    dst->part40[0] = 0;
    dst->part40[2] = 0;
    dst->part60[0] = 0;
    dst->part60[1] = 0;
    cVector_opAssign(&dst->rows[0], &src->rows[0]);
    cVector_opAssign(&dst->rows[1], &src->rows[1]);
    cVector_opAssign(&dst->rows[2], &src->rows[2]);
    cVector_opAssign(&dst->rows[3], &src->rows[3]);
    dst->flag50 = src->flag50;
    cCollisionModel_FaceProperties_opAssign(dst->part40, src->part40);
    cCollisionModel_FaceLocator_opAssign(dst->part60, src->part60);
    dst->flag51 = src->flag51;
    dst->flag52 = src->flag52;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00139B00 */
