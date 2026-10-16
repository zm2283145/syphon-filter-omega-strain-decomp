/*
 * main/DME: 2 files, 0042B8F0-0042B9E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042B8F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_0042B8F0)
#pragma pop /* merge_units */
/* merge_units: end func_0042B8F0 */

/* merge_units: begin func_0042B9E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after DME.cc (ends 0x0042ACD0),
 * before nellymoser_wrapper.c (starts 0x0042C1E0).
 */

#include "types.h"

Rel* func_0042B9E0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B9E0 */
