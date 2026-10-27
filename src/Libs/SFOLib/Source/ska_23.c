/*
 * Libs/SFOLib/Source/ska: 1 file, 003AF170
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AF170 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* lq/sq quad copy written as GCC-style volatile asm; the unused `xx` reproduces retail's dead addiu */
struct V { float x, y, z, w; V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; } } __attribute__((aligned(16)));
struct H0 { V m0; V m1; };
struct H2 { V m0; V m1; };
struct T5 { H0 m0; V m1; H2 m2; };
extern "C" T5* cSkaAnimAnchor_TreeNodeData_tData_ctor(T5* t, const T5* s);
T5* cSkaAnimAnchor_TreeNodeData_tData_ctor(T5* t, const T5* s) {
    *t = *s;
    return t;
}
static inline void merge_flush_func_003AF170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AF170 */
