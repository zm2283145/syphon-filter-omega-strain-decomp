#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) (*(d) = *(s))
struct E8_00241590 { int a[2]; };
#define VIFC_COPY(d, s) (*(E8_00241590*)(d) = *(const E8_00241590*)(s))
struct E_00241590 { float f0; unsigned char b4; };
DEFINE_VECTOR_INSERT_FILL_CSE(func_00241590, E_00241590, 0xC00000, 0x600000, D_004A6FE0, D_004A7148, 0x5C, func_00241A50, extern char D_004A7178[];, *tcount = 0; { E_00241590* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004A7178, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
