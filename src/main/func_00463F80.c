#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
struct B8_00463F80 { char a[8]; };
struct E_00463F80 { B8_00463F80 m0; int m1; };
DEFINE_VECTOR_INSERT_FILL_CNT(func_00463F80, E_00463F80, 0x800000, 0x400000, D_004C27C0, D_004C2578, 0x5C, func_00461D80, extern char D_004C2568[]; void func_00461FA0(func_00463F80_V* v);, func_00461FA0(&tmp); { E_00463F80* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004C2568, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
