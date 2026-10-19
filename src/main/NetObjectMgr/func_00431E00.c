#include "types.h"
#include "net_register_type.h"

typedef struct { short a; short b; } Proto_0020E420;
extern char D_00582758[];
extern void cNetTerrainActivationMsg_NetReceive(void);

NETREG_BEGIN(cNetTerrainActivationMsg_NetRegister, Proto_0020E420)
NETREG_FIELD(b, 2, 1)
NETREG_FIELD(a, 2, 1)
NETREG_END(D_00582758, cNetTerrainActivationMsg_NetReceive)
