#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4, (d)->m5 = (s)->m5)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4, (d)->m5 = (s)->m5)

struct E_003385A0 { int m0; int m1; char m2; int m3; int m4; int m5; };
DEFINE_VECTOR_INSERT_FILL_CNT(func_003385A0, E_003385A0, 0x400000, 0x200000, D_004B9320, D_004B9938, 0x5C, func_00338B20, void func_0033B590(func_003385A0_V* v, int flags);, func_0033B590(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
