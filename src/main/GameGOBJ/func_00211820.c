#include "types.h"
#include "net_register_type.h"

typedef struct { short a; int b; int c; } Proto_00211820;
extern char D_004F5470[];
extern void func_00211700(void);

NETREG_BEGIN(func_00211820, Proto_00211820)
NETREG_FIELD(a, 2, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(D_004F5470, func_00211700)
