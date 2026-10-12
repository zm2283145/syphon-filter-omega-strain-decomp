#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#define VIFC_ASSIGN(d, s) ((d)->a[0] = (s)->a[0], (d)->a[1] = (s)->a[1])
#define VIFC_COPY(d, s) (*(d) = *(s))
struct E_00339E30 { int a[2]; };
static char D_004B98F8[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CSE(func_00339E30, E_00339E30, 0xC00000, 0x600000, D_004B9320, D_004B98F8, 0x5C, func_0033A2F0, extern char D_004B98C8[];, *tcount = 0; { E_00339E30* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004B98C8, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
