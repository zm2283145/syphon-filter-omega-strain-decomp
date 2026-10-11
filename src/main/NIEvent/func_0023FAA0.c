#include "types.h"
#include "net_register_type.h"

typedef struct { int a; } Proto_0023FAA0;
extern char D_004F7C40[];
extern void func_0023F9A0(void);

NETREG_BEGIN_KEEP(func_0023FAA0, Proto_0023FAA0)
NETREG_FIELD(a, 4, 1)
NETREG_END(D_004F7C40, func_0023F9A0)
