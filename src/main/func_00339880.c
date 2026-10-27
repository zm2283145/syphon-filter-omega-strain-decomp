#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->a.m0 = (s)->a.m0, (d)->a.m1 = (s)->a.m1)
#define VIFC_COPY(d, s) ((d)->c.m0 = (s)->c.m0, (d)->c.m1 = (s)->c.m1)
struct G4_00339880 { int a[4]; };
struct B16_00339880 { char a[16]; };
union E_00339880 { struct { G4_00339880 m0; float m1; } c; struct { B16_00339880 m0; int m1; } a; };
static char D_004B9908[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CNT(std_vector_imp_PartData_insert, E_00339880, 0x4CCCCC, 0x266666, D_004B9320, D_004B9908, 0x5C, std_swap_vectordeleterR_vectordeleterR_34, void std_vector_deleter_PartData_dtor(std_vector_imp_PartData_insert_V* v, int flags);, std_vector_deleter_PartData_dtor(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
