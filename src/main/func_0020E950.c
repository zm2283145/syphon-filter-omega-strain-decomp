#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int pad; int b[4]; int c; char d; } Proto_0020E950;
extern char D_004F53E0[];
extern void func_0020E8B0(void);

NETREG_BEGIN(func_0020E950, Proto_0020E950)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 0x10, 1)
NETREG_FIELD(c, 4, 1)
NETREG_FIELD(d, 1, 1)
NETREG_END(D_004F53E0, func_0020E8B0)
