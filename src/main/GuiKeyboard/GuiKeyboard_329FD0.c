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
extern void func_00329930(S29930* dst, S29930* src);
extern V29F60* func_00329F60(V29F60* dst, V29F60* src);
E20* func_00329FD0(E20* first, E20* last, E20* result)
{
    while (first < last) {
        --last;
        --result;
        func_00329930(&result->s0, &last->s0);
        func_00329F60(&result->v, &last->v);
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

extern void* func_0013BCB0(void* dst, void* src);
extern Rel* func_0032A0B0(Rel* dst, Rel* src);

/* Copy constructor. */
Rec32A050* func_0032A050(Rec32A050* self, Rec32A050* src) {
    OwnedRel* vec;

    func_0013BCB0(self, src);
    vec = &self->vec;
    func_0032A0B0(&vec->vec, &src->vec.vec);
    vec->owned = src->vec.owned;
    self->unk1C = src->unk1C;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032A050 */
