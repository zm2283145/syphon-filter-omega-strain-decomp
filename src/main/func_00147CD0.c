#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) (*(d) = *(s))
#define VIFC_COPY(d, s) (*(d) = *(s))
static char D_0049B330[] = "vector::insert length error\n";
struct EA_00147CD0 { int a[6]; };
struct E_00147CD0 { int i0, i1, i2, i3, i4, i5; };
DEFINE_VECTOR_INSERT_FILL_CNT(func_00147CD0, E_00147CD0, 0x400000, 0x200000, D_0049B330, D_0049B408, 0x5C, func_00148250, void func_00148380(func_00147CD0_V* v, int flags);, func_00148380(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
