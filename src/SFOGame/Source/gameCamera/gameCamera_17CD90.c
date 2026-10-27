/*
 * main/gameCamera: range (2 files, 0017CD90-0017CDB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0017CD90 */
#pragma push /* merge_units */
/* Retail computes each quadword address separately (peephole pass off). */
#pragma peephole off

typedef struct { Vec4 a; Vec4 b; } VecPair;

static inline Vec4* CopyVec(Vec4* d, Vec4* s)
{
    *d = *s;
    return d;
}

/* Copies a pair of 16-byte vectors; returns the destination. */
VecPair* cQuatVec_ctor_cQuatVecR(VecPair* dst, VecPair* src)
{
    CopyVec(&dst->a, &src->a);
    CopyVec(&dst->b, &src->b);
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017CD90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017CD90 */

/* merge_units: begin func_0017CDB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Vector of 16-byte records: +4 count, +8 data. */
typedef struct VecRecordList {
    int unk0;
    int count;
    char* data;
} VecRecordList;

extern int std_vector_imp_cVector_insert(VecRecordList* list, char* pos, int n, int value);

/* Appends one record at the end of the list. */
int cArray_cVector_PushBackActual(VecRecordList* list, int value) {
    return std_vector_imp_cVector_insert(list, list->data + (list->count << 4), 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017CDB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017CDB0 */
