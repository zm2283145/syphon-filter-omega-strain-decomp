/*
 * main/materialProperties: 2 files, 00408D80-00408DF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00408D80 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int m0; void* m4; } T8D80;
extern void func_0040A9C0(T8D80* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor of a tree owner: erase the root, then delete. */
T8D80* func_00408D80(T8D80* t, short del)
{
    if (t) {
        if (t) {
            if (t->m4)
                func_0040A9C0(t, t->m4);
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_00408D80 */

/* merge_units: begin func_00408DF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int String_CopyCtor(L4Elem124Vec*, int);

void func_00408DF0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* end() of the element vector. */
L4Elem124* func_00408E00(L4Elem124Vec* v) {
    return v->data + v->count;
}

int func_00408E30(L4Elem124Vec* v, int a1, int value) {
    int ret = String_CopyCtor(v, a1);

    v->unk0C = value;
    return ret;
}

Word* func_00408E70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00408E80(Iter* out, Tree* t) {
    out->p = &t->header;
}

void* func_00408E90(char* self) {
    return self + 8;
}
#pragma pop /* merge_units */
/* merge_units: end func_00408DF0 */
