#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
struct B8_00462690 { char a[8]; };
struct E_00462690 { B8_00462690 m0; int m1; };
extern "C" char D_004C26D0[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CNT(func_00462690, E_00462690, 0x800000, 0x400000, D_004C26D0, D_004C2578, 0x5C, func_00461D80, extern char D_004C2568[]; void func_00461FA0(func_00462690_V* v);, func_00461FA0(&tmp); { E_00462690* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004C2568, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)

