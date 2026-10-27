#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) (*(d) = *(s))
#define VIFC_COPY(d, s) (*(d) = *(s))
struct E_0022A360 { int f0; };
static char D_004A6440[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CSE(std_vector_imp_cString4_insert, E_0022A360, 0x1800000, 0xC00000, D_004A6440, D_004A6460, 0x5C, std_swap_vectordeleterR_vectordeleterR_18, void std_vector_deleter_cString4_dtor(std_vector_imp_cString4_insert_V* v, int flags);, std_vector_deleter_cString4_dtor(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
