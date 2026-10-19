#include "types.h"
#include "net_register_type.h"

typedef struct { short a; int b; int c; } Proto_00211820;
extern char D_004F5470[];
extern void cGOBJTriggerEventMsg_NetReceive(void);

NETREG_BEGIN(cGOBJTriggerEventMsg_NetRegister, Proto_00211820)
NETREG_FIELD(a, 2, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(D_004F5470, cGOBJTriggerEventMsg_NetReceive)
