/*
 * main/GuiKeyboard: 2 files, 00329EB0-00329EF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00329EB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_27(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_00329EB0 */

/* merge_units: begin func_00329EF0 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } G4_A;
typedef struct { int a, b, c, d; } G4_B;
typedef struct { G4_A a; G4_B b; int c; } G4_E20;
extern void cString_opAssign(G4_A* d, G4_A* s);
extern void cArray_Slide_opAssign(G4_B* d, G4_B* s);
void std_fill_n_Section_int_fill_n(G4_E20* p, unsigned int n, G4_E20* v)
{
    for (; n != 0; n--, p++) {
        cString_opAssign(&p->a, &v->a);
        cArray_Slide_opAssign(&p->b, &v->b);
        p->c = v->c;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00329EF0 */
