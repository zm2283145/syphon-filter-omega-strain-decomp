/*
 * SFOGame/Source/humanAnimData: 1 file, 001F37C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F37C0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Obj3 {
    int a;
    int b;
    int c;
} Obj3;

extern void compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_uint(Obj3*, int);

/* Constructor: compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_uint(self, 0), then clears +4 and +8. */
Obj3* std_vector_deleter_cSkaTransBLEND_ctor_void(Obj3* o) {
    compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_uint(o, 0);
    o->b = 0;
    o->c = 0;
    return o;
}
static inline void merge_flush_func_001F37C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F37C0 */
