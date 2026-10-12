#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4)

struct E_00339270 { int m0; int m1; char m2; int m3; int m4; };
static char D_004B9918[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CNT(func_00339270, E_00339270, 0x4CCCCC, 0x266666, D_004B9320, D_004B9918, 0x5C, func_00339840, extern char D_004AA5B8[];, *tcount = 0; { E_00339270* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004AA5B8, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
