/*
 * main/GuiGameScreen: 2 files, 004612A0-00461770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004612A0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_004C2500[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(Vector_Insert_4612A0, 0x1800000, 0xC00000, D_004C2500, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_004612A0 */

/* merge_units: begin func_00461770 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
struct B8_00461770 { char a[8]; };
struct E_00461770 { B8_00461770 m0; int m1; };
DEFINE_VECTOR_INSERT_FILL_CNT(std_vector_imp_tQuip_insert, E_00461770, 0x800000, 0x400000, D_004C2500, D_004C2578, 0x5C, std_swap_vectordeleterR_vectordeleterR_52, extern char D_004C2568[]; void func_00461FA0(std_vector_imp_tQuip_insert_V* v);, func_00461FA0(&tmp); { E_00461770* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004C2568, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
#pragma pop /* merge_units */
/* merge_units: end func_00461770 */
