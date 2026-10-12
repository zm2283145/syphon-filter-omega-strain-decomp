#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) (*(d) = *(s))
#define VIFC_COPY(d, s) (*(d) = *(s))
struct E_0022A360 { int f0; };
static char D_004A6440[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CSE(func_0022A360, E_0022A360, 0x1800000, 0xC00000, D_004A6440, D_004A6460, 0x5C, func_0022A770, void func_001C4480(func_0022A360_V* v, int flags);, func_001C4480(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
