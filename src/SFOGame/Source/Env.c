/*
 * SFOGame/Source/Env: 1 file, 00174B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00174B60 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) (*(d) = *(s))
#define VIFC_COPY(d, s) (*(d) = *(s))
static char D_0049CA80[] = "vector::insert length error\n";
struct E_00174B60 { int f0; };
DEFINE_VECTOR_INSERT_FILL_CSE(std_vector_imp_cObjectId_insert, E_00174B60, 0x1800000, 0xC00000, D_0049CA80, D_0049CAD8, 0x5C, std_swap_vectordeleterR_vectordeleterR_5, extern char D_0049CAC8[];, *tcount = 0; { E_00174B60* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049CAC8, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
static inline void merge_flush_func_00174B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174B60 */
