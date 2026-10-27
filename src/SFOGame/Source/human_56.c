/*
 * SFOGame/Source/human: 2 files, 001989E0-00198A20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001989E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int opNe_cConstLListIteratorR_cConstLListIteratorR(Iter* a, Iter* b) {
    return a->p != b->p;
}

/* List iterator ++: follow the next link at node +0x04. */
Iter* cConstLListIterator_cSkaPlaybackGroupPtr_opInc(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}
static inline void merge_flush_func_001989E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001989E0 */

/* merge_units: begin func_00198A20 */
#pragma push /* merge_units */
typedef struct { int a; int b; } E2Key;
typedef struct { int id; char list[4]; } E2Motion;
extern int cArray_cSkaPlaybackItem_Size(void*);
extern void* cArray_cSkaPlaybackItem_opIndex(void*, int);
extern void* cSkaPlaybackItem_GetAnimation(void*);
extern E2Key* cSkaPlaybackGroupId_ctor_cSkaAnimR(E2Key*, void*);
extern E2Key* cSkaPlaybackGroupId_ctor_int(E2Key*, int);
extern void cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(E2Key*, E2Key*);
int cSkaPlaybackGroup_CheckId(E2Motion* m, E2Key* key) {
    E2Key cur;
    E2Key t1;
    E2Key t0;
    E2Key* k;
    if (cArray_cSkaPlaybackItem_Size(m->list) == 1) {
        k = cSkaPlaybackGroupId_ctor_cSkaAnimR(&t1, cSkaPlaybackItem_GetAnimation(cArray_cSkaPlaybackItem_opIndex(m->list, 0)));
    } else {
        k = cSkaPlaybackGroupId_ctor_int(&t0, m->id);
    }
    cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(&cur, k);
    return key->a == cur.a && key->b == cur.b;
}
static inline void merge_flush_func_00198A20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198A20 */
