/*
 * SFOGame/Source/path: 1 file, 0015CC70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015CC70 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
struct I_0015CC70 { int a; int b; };
struct F_0015CC70 { float x; float y; };
union E_0015CC70 { F_0015CC70 f; I_0015CC70 i; };
#define VIFC_ASSIGN(d, s) ((d)->i = (s)->i)
#define VIFC_COPY(d, s) (*(d) = *(s))
static char D_0049C150[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CNT(std_vector_imp_tNodeLink_insert, E_0015CC70, 0xC00000, 0x600000, D_0049C150, D_0049C198, 0x5C, std_swap_vectordeleterR_vectordeleterR_3, extern char D_0049C1A8[];, *tcount = 0; { E_0015CC70* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049C1A8, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
static inline void merge_flush_func_0015CC70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015CC70 */
