#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->a.m0 = (s)->a.m0, (d)->a.m1 = (s)->a.m1)
#define VIFC_COPY(d, s) ((d)->c.m0 = (s)->c.m0, (d)->c.m1 = (s)->c.m1)
struct G4_00339880 { int a[4]; };
struct B16_00339880 { char a[16]; };
union E_00339880 { struct { G4_00339880 m0; float m1; } c; struct { B16_00339880 m0; int m1; } a; };
static char D_004B9908[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CNT(func_00339880, E_00339880, 0x4CCCCC, 0x266666, D_004B9320, D_004B9908, 0x5C, func_00339DF0, void func_0033B770(func_00339880_V* v, int flags);, func_0033B770(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
