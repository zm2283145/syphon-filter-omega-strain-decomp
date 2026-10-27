/*
 * Libs/SFOLib/Source/globalization: 1 file, 003FE800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FE800 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0)

struct E_003FE800 { __int128 m0; };
extern "C" char D_004BE4D0[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CNT(insert__Q23std33__vector_impTFP1UiRC1, E_003FE800, 0x600000, 0x300000, D_004BE4D0, D_004BE530, 0x5C, std_swap_vectordeleterR_vectordeleterR_46, extern char D_004BE520[];, *tcount = 0; { E_003FE800* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004BE520, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
static inline void merge_flush_func_003FE800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FE800 */
