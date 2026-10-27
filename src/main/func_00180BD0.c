#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_v2.h"
struct E_00180BD0 { __int128 q; ~E_00180BD0() {} };
#define VIF2_COPY(d, s) (*(d) = *(s))
/* whole-function settings; left in effect because C++ code generation is deferred to end of file */
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_code off
#pragma opt_loop_invariants off
DEFINE_VECTOR_INSERT_FILL_V2(std_vector_imp_cVector_insert, E_00180BD0, 0x600000, D_0049CE20, D_0049CEB8, 0x5C, std_swap_vectordeleterR_vectordeleterR_6, extern char D_0049CEA8[];, VIF2_FREE(E_00180BD0, D_0049CEA8, 0x64), VIF2_COPY, VIF2_COPY)
