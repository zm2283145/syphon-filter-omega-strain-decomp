#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) ((d)->x = (s)->x, (d)->y = (s)->y, (d)->z = (s)->z, (d)->w = (s)->w)
struct E16_00240760 { int a[4]; };
#define VIFC_COPY(d, s) (*(E16_00240760*)(d) = *(const E16_00240760*)(s))
struct E_00240760 { float x, y, z, w; };
static char D_004A7168[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CSE(func_00240760, E_00240760, 0x600000, 0x300000, D_004A6FE0, D_004A7168, 0x5C, func_00240CA0, extern char D_004A7198[];, *tcount = 0; { E_00240760* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004A7198, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
