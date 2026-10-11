#include "types.h"
#include "net_register_type.h"

typedef struct { int a; } Proto_0022E240;
extern char D_004F7958[];
extern void func_0022E320(void);

NETREG_BEGIN(func_0022E240, Proto_0022E240)
NETREG_FIELD(a, 4, 1)
NETREG_END(D_004F7958, func_0022E320)
