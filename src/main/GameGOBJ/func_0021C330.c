#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_v2.h"
struct E_0021C330 { __int128 q; ~E_0021C330() {} };
#define VIF2_COPY(d, s) (*(d) = *(s))
/* whole-function settings; left in effect because C++ code generation is deferred to end of file */
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_code off
#pragma opt_loop_invariants off
static char D_004A4650[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_V2(func_0021C330, E_0021C330, 0x600000, D_004A4650, D_004A49E8, 0x5C, func_0021C7E0, extern char D_004A49F8[];, VIF2_FREE(E_0021C330, D_004A49F8, 0x64), VIF2_COPY, VIF2_COPY)
