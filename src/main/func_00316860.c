#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int b; } Proto_0020E420;
extern char D_0052ACB8[];
extern void func_003167C0(void);

NETREG_BEGIN(func_00316860, Proto_0020E420)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 4, 1)
NETREG_END(D_0052ACB8, func_003167C0)
