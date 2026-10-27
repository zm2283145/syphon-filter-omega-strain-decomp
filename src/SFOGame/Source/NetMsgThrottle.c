/*
 * SFOGame/Source/NetMsgThrottle: 1 file, 00471BF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00471BF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after inventory.cc (ends 0x004719B0),
 * before NetMsgThrottle.cc (starts 0x00472050).
 */

#include "types.h"

extern int std_vector_imp_tRecord_reserve(int, int);

int func_00471BF0(int a0, int a1) {
    return std_vector_imp_tRecord_reserve(a0, a1);
}

Rel* func_00471C00(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00471BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00471BF0 */
