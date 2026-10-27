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

