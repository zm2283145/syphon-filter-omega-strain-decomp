/*
 * main/materialProperties: 2 files, 00409DF0-00409E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00409DF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00409DF0(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_00409DF0 */

/* merge_units: begin func_00409E30 */
#pragma push /* merge_units */
typedef struct { char d[0x38]; } E124;
typedef struct { char base[0xC]; E124 e[5]; } T124;
extern void func_00329930(T124* d, const T124* s);
extern void func_00409EC0(E124* d, const E124* s);
static inline void t124_assign(T124* d, const T124* s) {
    E124* a;
    const E124* b;
    func_00329930(d, s);
    a = d->e;
    b = s->e;
    do {
        func_00409EC0(a, b);
        a++;
        b++;
    } while (a != d->e + 5);
}/* Fills n records with a copy of v. */
void func_00409E30(T124* d, unsigned int n, const T124* v) {
    for (; n != 0; n--, d++)
        t124_assign(d, v);
}
#pragma pop /* merge_units */
/* merge_units: end func_00409E30 */
