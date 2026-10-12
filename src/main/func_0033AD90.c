#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) (*(d) = *(s))
#define VIFC_COPY(d, s) (*(d) = *(s))
struct EA_0033AD90 { int a[8]; };
struct E_0033AD90 { int i0, i1, i2, i3, i4, i5, i6, i7; };
DEFINE_VECTOR_INSERT_FILL_CSE(func_0033AD90, E_0033AD90, 0x300000, 0x180000, D_004B9320, D_004B98A8, 0x5C, func_0033B3D0, extern char D_004B98E8[];, *tcount = 0; { E_0033AD90* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004B98E8, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
