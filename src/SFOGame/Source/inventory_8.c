/*
 * SFOGame/Source/inventory: 1 file, 00470E10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00470E10 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) ((d)->a[0] = (s)->a[0], (d)->a[1] = (s)->a[1])
#define VIFC_COPY(d, s) (*(d) = *(s))
struct E_00470E10 { int a[2]; };
extern "C" char D_004C3400[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CSE(std_vector_imp_tItem_insert, E_00470E10, 0xC00000, 0x600000, D_004C3360, D_004C3400, 0x5C, std_swap_vectordeleterR_vectordeleterR_53, void std_vector_deleter_tItem_dtor(std_vector_imp_tItem_insert_V* v, int flags);, std_vector_deleter_tItem_dtor(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
static inline void merge_flush_func_00470E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00470E10 */
