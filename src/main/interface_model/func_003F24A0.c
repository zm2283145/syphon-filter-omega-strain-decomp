#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) ((d)->x = (s)->x, (d)->y = (s)->y)
#define VIFC_COPY(d, s) ((d)->x = (s)->x, (d)->y = (s)->y)
struct E_003F24A0 { float x, y; };
DEFINE_VECTOR_INSERT_FILL_CSE(func_003F24A0, E_003F24A0, 0xC00000, 0x600000, D_004BE0E0, D_004BE170, 0x5C, func_003F2970, extern char D_004BE140[]; void func_003F4390(func_003F24A0_V* v);, func_003F4390(&tmp); { E_003F24A0* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004BE140, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
