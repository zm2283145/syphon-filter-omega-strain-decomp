/*
 * main/message: 4 files, 003CA3E0-003CA4D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CA3E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003CA3E0(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA3E0 */

/* merge_units: begin func_003CA3F0 */
#pragma push /* merge_units */
typedef struct { int m0; int m4; int m8; } TA3F0;
extern void func_003C9EA0(int* out, TA3F0* self, int* first, int* last);
extern void operator_delete(void* p);
TA3F0* func_003CA3F0(TA3F0* self, short del)
{
    if (self) {
        int r;
        int first;
        int last;
        last = (int)&self->m4;
        first = self->m8;
        func_003C9EA0(&r, self, &first, &last);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA3F0 */

/* merge_units: begin func_003CA460 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } TB5C0;
extern void func_003CA530(TB5C0* t, void* n);
TB5C0* func_003CA460(TB5C0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_003CA530(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA460 */

/* merge_units: begin func_003CA4D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_003CA4D0, func_003CA360)
#pragma pop /* merge_units */
/* merge_units: end func_003CA4D0 */
