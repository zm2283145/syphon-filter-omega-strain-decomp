#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; } Proto_0020E420;
extern char D_004F53A0[];
extern void func_0020E350(void);

NETREG_BEGIN(func_0020E420, Proto_0020E420)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_END(D_004F53A0, func_0020E350)
