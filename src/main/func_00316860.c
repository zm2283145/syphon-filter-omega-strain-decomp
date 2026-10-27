#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int b; } Proto_0020E420;
extern char D_0052ACB8[];
extern void cNetShatterMsg_NetShatterMsgCallback(void);

NETREG_BEGIN(cNetShatterMsg_InitNet, Proto_0020E420)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 4, 1)
NETREG_END(D_0052ACB8, cNetShatterMsg_NetShatterMsgCallback)
