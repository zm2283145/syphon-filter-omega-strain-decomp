#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0)

struct E_003FE800 { __int128 m0; };
extern "C" char D_004BE4D0[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CNT(func_003FE800, E_003FE800, 0x600000, 0x300000, D_004BE4D0, D_004BE530, 0x5C, func_003FEC90, extern char D_004BE520[];, *tcount = 0; { E_003FE800* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004BE520, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)

