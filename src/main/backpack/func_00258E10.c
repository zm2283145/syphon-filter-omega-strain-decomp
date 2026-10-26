#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_tw.h"

struct VIElemIF { int a; float b; };
extern "C" { char D_004A7B60[] = "vector::insert length error\n"; }
DEFINE_VECTOR_INSERT_FILL_TW(HandleVec_Insert, VIElemIF, 0xC00000, 0x600000, D_004A7B60, D_004A7C58, 0x5C, std_swap_vectordeleterR_vectordeleterR_23, std_vector_deleter_cSafePtr_cGOBJ_dtor)
