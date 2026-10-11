#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int pad; int b[4]; int c; int d; char e; } Proto_0020F540;
extern char D_004F53C0[];
extern void func_0020F4A0(void);

NETREG_BEGIN(func_0020F540, Proto_0020F540)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 0x10, 1)
NETREG_FIELD(c, 4, 1)
NETREG_FIELD(d, 4, 1)
NETREG_FIELD(e, 1, 1)
NETREG_END(D_004F53C0, func_0020F4A0)
