/*
 * main/human: range (3 files, 00198AD0-00198B20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00198AD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(int* dst, int* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198AD0 */

/* merge_units: begin func_00198AF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; int key; } MotionGroup;
typedef struct { MotionGroup* group; int key; } MotionKey;
/* Build a key handle: the group is set only when its key is unassigned (-1). */
MotionKey* cSkaPlaybackGroupId_ctor_cSkaAnimR(MotionKey* out, MotionGroup* group)
{
    out->group = group->key == -1 ? group : 0;
    out->key = group->key;
    return out;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198AF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198AF0 */

/* merge_units: begin func_00198B20 */
#pragma push /* merge_units */
int cSkaPlaybackItem_GetAnimation(char* self) {
    return *(int*)(self + 0);
}

/* Address of 32-byte element i. */
char* cArray_cSkaPlaybackItem_opIndex(PtrVec* v, int i) {
    return (char*)v->data + (i << 5);
}

int cArray_cSkaPlaybackItem_Size(char* self) {
    return *(int*)(self + 4);
}

char* cConstLListIterator_cSkaPlaybackGroupPtr_opMul(Iter* it) {
    return (char*)it->p + 8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198B20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198B20 */
