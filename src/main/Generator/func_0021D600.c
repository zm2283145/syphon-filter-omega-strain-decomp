#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; short c; } Proto_0021D600;
extern char D_004F56C8[];
extern void func_0021D6C0(void);

NETREG_BEGIN_KEEP(func_0021D600, Proto_0021D600)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 2, 1)
NETREG_END(D_004F56C8, func_0021D6C0)
