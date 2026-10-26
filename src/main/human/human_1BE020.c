/*
 * main/human: 2 files, 001BE020-001BE090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BE020 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_resize.h"

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_cSkaSwitchValue_resize, Elem8, Vector_Insert_1BF5A0, std_vector_imp_cSkaSwitchValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_001BE020 */

/* merge_units: begin func_001BE090 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)

static char D_0049ED48[] = "allocator.hh";
struct E_001BE090 { unsigned char m0; float m1; };
DEFINE_VECTOR_INSERT_FILL_CNT(Vector_Insert_1BE090, E_001BE090, 0xC00000, 0x600000, D_0049E980, D_0049ED48, 0x5C, std_swap_vectordeleterR_vectordeleterR_8, extern char D_0049ED28[]; void func_001BFA30(Vector_Insert_1BE090_V* v);, func_001BFA30(&tmp); { E_001BE090* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049ED28, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
#pragma pop /* merge_units */
/* merge_units: end func_001BE090 */
