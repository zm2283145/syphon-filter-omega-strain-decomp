#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) (*(d) = *(s))
#define VIFC_COPY(d, s) (*(d) = *(s))
struct E_00174B60 { int f0; };
DEFINE_VECTOR_INSERT_FILL_CSE(func_00174B60, E_00174B60, 0x1800000, 0xC00000, D_0049CA80, D_0049CAD8, 0x5C, func_00174FF0, extern char D_0049CAC8[];, *tcount = 0; { E_00174B60* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049CAC8, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
