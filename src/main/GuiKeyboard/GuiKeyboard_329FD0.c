/*
 * main/GuiKeyboard: 2 files, 00329FD0-0032A050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00329FD0 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } S29930;
typedef struct { int first; int count; void* buf; char flag; } V29F60;
typedef struct { S29930 s0; V29F60 v; int x; } E20;
extern void cString_opAssign(S29930* dst, S29930* src);
extern V29F60* cArray_Slide_opAssign(V29F60* dst, V29F60* src);
E20* std_copy_backward_Section_copy_backward(E20* first, E20* last, E20* result)
{
    while (first < last) {
        --last;
        --result;
        cString_opAssign(&result->s0, &last->s0);
        cArray_Slide_opAssign(&result->v, &last->v);
        result->x = last->x;
    }
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_00329FD0 */

/* merge_units: begin func_0032A050 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern void* String_CopyCtor(void* dst, void* src);
extern Rel* std_vector_Slide_ctor(Rel* dst, Rel* src);

/* Copy constructor. */
Rec32A050* GuiSlideShow_Section_ctor(Rec32A050* self, Rec32A050* src) {
    OwnedRel* vec;

    String_CopyCtor(self, src);
    vec = &self->vec;
    std_vector_Slide_ctor(&vec->vec, &src->vec.vec);
    vec->owned = src->vec.owned;
    self->unk1C = src->unk1C;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032A050 */
