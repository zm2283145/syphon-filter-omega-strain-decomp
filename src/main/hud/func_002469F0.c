#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->a.m0 = (s)->a.m0, (d)->a.m1 = (s)->a.m1, (d)->a.m2 = (s)->a.m2)
#define VIFC_COPY(d, s) ((d)->c.m0 = (s)->c.m0)
struct B33_002469F0 { char a[33]; };
struct B16_002469F0 { char a[16]; };
union E_002469F0 { struct { B33_002469F0 m0; } c; struct { unsigned char m0; B16_002469F0 m1; B16_002469F0 m2; } a; };
static char D_004A7450[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CNT(Vector_Insert_2469F0, E_002469F0, 0x2E8BA2, 0x1745D1, D_004A7450, D_004A74F8, 0x5C, func_00246FB0, void func_00246FF0(Vector_Insert_2469F0_V* v, int flags);, func_00246FF0(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
