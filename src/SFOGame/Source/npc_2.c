/*
 * SFOGame/Source/npc: 1 file, 00147CD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin npc_147CD0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) (*(d) = *(s))
#define VIFC_COPY(d, s) (*(d) = *(s))
static char D_0049B330[] = "vector::insert length error\n";
struct EA_00147CD0 { int a[6]; };
struct E_00147CD0 { int i0, i1, i2, i3, i4, i5; };
DEFINE_VECTOR_INSERT_FILL_CNT(std_vector_imp_Record_insert, E_00147CD0, 0x400000, 0x200000, D_0049B330, D_0049B408, 0x5C, std_swap_vectordeleterR_vectordeleterR_2, void std_vector_deleter_Record_dtor(std_vector_imp_Record_insert_V* v, int flags);, std_vector_deleter_Record_dtor(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
static inline void merge_flush_npc_147CD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end npc_147CD0 */
