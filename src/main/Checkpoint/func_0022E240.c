#include "types.h"
#include "net_register_type.h"

typedef struct { int a; } Proto_0022E240;
extern char D_004F7958[];
extern void cRespawnMsg_RespawnMsgCallback(void);

NETREG_BEGIN(cRespawnMsg_InitNet, Proto_0022E240)
NETREG_FIELD(a, 4, 1)
NETREG_END(D_004F7958, cRespawnMsg_RespawnMsgCallback)
