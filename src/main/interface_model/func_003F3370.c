#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
struct A3_003F3370 { int a[3]; };
#define VIFC_ASSIGN(d, s) ((d)->f0 = (s)->f0, *(A3_003F3370*)&(d)->v = *(const A3_003F3370*)&(s)->v)
#define VIFC_COPY(d, s) ((d)->f0 = (s)->f0, (d)->v.x = (s)->v.x, (d)->v.y = (s)->v.y, (d)->v.z = (s)->v.z)
struct EA_003F3370 { int a[4]; };
struct V3_003F3370 { float x, y, z; };
struct E_003F3370 { float f0; V3_003F3370 v; };
DEFINE_VECTOR_INSERT_FILL_CSE(func_003F3370, E_003F3370, 0x600000, 0x300000, D_004BE0E0, D_004BE150, 0x5C, std_swap_vectordeleterR_vectordeleterR_45, extern char D_004BE120[]; void func_003F43B0(func_003F3370_V* v);, func_003F43B0(&tmp); { E_003F3370* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004BE120, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
