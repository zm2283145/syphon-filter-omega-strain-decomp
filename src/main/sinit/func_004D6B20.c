#include "types.h"
#include "vu0_ops.h"
extern char g_IdentityMatrix[];
void StaticInit_sfomath(void) {
    VU0_UnitMatrix(g_IdentityMatrix);
}
