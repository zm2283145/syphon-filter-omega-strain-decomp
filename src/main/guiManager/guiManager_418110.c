/*
 * main/guiManager: 5 files, 00418110-004182C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00418110 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00418110(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_00418110 */

/* merge_units: begin func_00418150 */
#pragma push /* merge_units */
typedef struct { char p0[12]; signed char fC; char pD[3]; int f10; int f14; } E418;
int func_00329930(E418 *, E418 *);
static inline void cc418(E418 *d, E418 *s) { func_00329930(d, s); d->fC = s->fC; d->f10 = s->f10; d->f14 = s->f14; }
void func_00418150(E418 *p, int n, E418 *v) {
    for (; n != 0; --n, ++p) cc418(p, v);
}
#pragma pop /* merge_units */
/* merge_units: end func_00418150 */

/* merge_units: begin func_004181C0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int func_00329930(char * , char * );
#endif /* merge_units */
#define func_00329930(a0, a1) (func_00329930((E418 *)(a0), (E418 *)(a1))) /* merge_units */
                    

#pragma opt_propagation off
char * func_004181C0(unsigned int arg0, unsigned int arg1, char * arg2) {
    unsigned int var_s1;
    char * var_s0;

    var_s1 = arg1;
    var_s0 = arg2;
    if (arg0 < var_s1) {
        do {
            var_s1 -= 0x18;
            var_s0 -= 0x18;
            func_00329930(var_s0, (char * ) var_s1);
            F_(var_s0, 0xC, signed char) = F_(var_s1, 0xC, signed char);
            F_(var_s0, 0x10, int) = F_(var_s1, 0x10, int);
            F_(var_s0, 0x14, int) = F_(var_s1, 0x14, int);
        } while (arg0 < var_s1);
    }
    return var_s0;
}
#undef func_00329930 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004181C0 */

/* merge_units: begin func_00418240 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
extern "C" { char D_004BF0A0[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(func_00418240, func_004183A0, func_004182C0, D_004BF0A0)
#pragma pop /* merge_units */
/* merge_units: end func_00418240 */

/* merge_units: begin func_004182C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_004182C0, func_00138350)
#pragma pop /* merge_units */
/* merge_units: end func_004182C0 */
