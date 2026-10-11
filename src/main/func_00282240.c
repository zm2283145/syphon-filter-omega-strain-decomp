#include "types.h"
#include "net_register_type.h"

typedef struct { short a; short b; char c[0x100]; } Proto_00282240;
extern char D_005061C8[];
extern void func_002822F0(void);

NETREG_BEGIN(func_00282240, Proto_00282240)
NETREG_FIELD(b, 2, 1)
NETREG_FIELD(a, 2, 1)
NETREG_FIELD(c, 1, 0x100)
NETREG_END(D_005061C8, func_002822F0)
