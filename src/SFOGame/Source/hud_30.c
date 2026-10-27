/*
 * SFOGame/Source/hud: 1 file, 002469F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002469F0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->a.m0 = (s)->a.m0, (d)->a.m1 = (s)->a.m1, (d)->a.m2 = (s)->a.m2)
#define VIFC_COPY(d, s) ((d)->c.m0 = (s)->c.m0)
struct B33_002469F0 { char a[33]; };
struct B16_002469F0 { char a[16]; };
union E_002469F0 { struct { B33_002469F0 m0; } c; struct { unsigned char m0; B16_002469F0 m1; B16_002469F0 m2; } a; };
static char D_004A7450[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CNT(std_vector_imp_PDAQuip_insert, E_002469F0, 0x2E8BA2, 0x1745D1, D_004A7450, D_004A74F8, 0x5C, std_swap_vectordeleterR_vectordeleterR_22, void std_vector_deleter_PDAQuip_dtor(std_vector_imp_PDAQuip_insert_V* v, int flags);, std_vector_deleter_PDAQuip_dtor(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
static inline void merge_flush_func_002469F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002469F0 */
