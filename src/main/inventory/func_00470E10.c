#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) ((d)->a[0] = (s)->a[0], (d)->a[1] = (s)->a[1])
#define VIFC_COPY(d, s) (*(d) = *(s))
struct E_00470E10 { int a[2]; };
DEFINE_VECTOR_INSERT_FILL_CSE(func_00470E10, E_00470E10, 0xC00000, 0x600000, D_004C3360, D_004C3400, 0x5C, func_00471250, void func_001BE780(func_00470E10_V* v, int flags);, func_001BE780(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
