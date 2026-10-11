#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; int c; } Proto_00211820;
extern char D_00582748[];
extern void func_00431A70(void);

NETREG_BEGIN(func_00431B10, Proto_00211820)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(D_00582748, func_00431A70)
