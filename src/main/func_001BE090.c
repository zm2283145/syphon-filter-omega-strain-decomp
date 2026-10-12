#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)

struct E_001BE090 { unsigned char m0; float m1; };
DEFINE_VECTOR_INSERT_FILL_CNT(func_001BE090, E_001BE090, 0xC00000, 0x600000, D_0049E980, D_0049ED48, 0x5C, func_001BE560, extern char D_0049ED28[]; void func_001BFA30(func_001BE090_V* v);, func_001BFA30(&tmp); { E_001BE090* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049ED28, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
