#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4)

struct E_00339270 { int m0; int m1; char m2; int m3; int m4; };
static char D_004B9918[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CNT(std_vector_imp_tAchievementInfo_insert, E_00339270, 0x4CCCCC, 0x266666, D_004B9320, D_004B9918, 0x5C, std_swap_vectordeleterR_vectordeleterR_33, extern char D_004AA5B8[];, *tcount = 0; { E_00339270* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004AA5B8, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
