#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int b; int c; } Proto_00316550;
extern char D_0052ACA8[];
extern void func_00316480(void);

NETREG_BEGIN(func_00316550, Proto_00316550)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(D_0052ACA8, func_00316480)
