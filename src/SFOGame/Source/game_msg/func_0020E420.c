#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; } Proto_0020E420;
extern char D_004F53A0[];
extern void cEndLevelMsg_NetEndLevelCallback(void);

NETREG_BEGIN(cEndLevelMsg_InitNet, Proto_0020E420)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_END(D_004F53A0, cEndLevelMsg_NetEndLevelCallback)
