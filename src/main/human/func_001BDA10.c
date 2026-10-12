#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->a.m0 = (s)->a.m0, (d)->a.m1 = (s)->a.m1, (d)->a.m2 = (s)->a.m2)
#define VIFC_COPY(d, s) ((d)->c.m0 = (s)->c.m0, (d)->c.m1 = (s)->c.m1, (d)->c.m2 = (s)->c.m2, (d)->c.m3 = (s)->c.m3, (d)->c.m4 = (s)->c.m4)
struct G3_001BDA10 { int a[3]; };
union E_001BDA10 { struct { float m0; float m1; unsigned char m2; int m3; int m4; } c; struct { G3_001BDA10 m0; int m1; int m2; } a; };
DEFINE_VECTOR_INSERT_FILL_CNT(func_001BDA10, E_001BDA10, 0x4CCCCC, 0x266666, D_0049E980, D_0049ED58, 0x5C, func_001BDFE0, extern char D_0049ED38[]; void func_001BFA20(func_001BDA10_V* v);, func_001BFA20(&tmp); { E_001BDA10* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049ED38, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
