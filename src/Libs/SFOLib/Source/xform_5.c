/*
 * Libs/SFOLib/Source/xform: 3 files, 0036FB90-0036FCD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036FB90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cXformNodePtr_1_dtor)
static inline void merge_flush_func_0036FB90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FB90 */

/* merge_units: begin func_0036FC80 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Deleting destructor of a class with nothing to destroy: restore the vtable, delete. */
extern "C" {
extern char D_004DF6A0[];
void operator_delete(void* allocation);
}
struct O36FC80 { void* vtable; };
extern "C" O36FC80* cXform_dtor(O36FC80* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DF6A0;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0036FC80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FC80 */

/* merge_units: begin func_0036FCD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* std_vector_cXformNodePtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_0036FCD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FCD0 */
