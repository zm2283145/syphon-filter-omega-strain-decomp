#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; } Proto_0021D190;
extern char D_004F56D0[];
extern void cGeneratorDataMessage_GeneratorDataMessageCallback(void);

NETREG_BEGIN_KEEP(cGeneratorDataMessage_InitNet, Proto_0021D190)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(a, 1, 1)
NETREG_END(D_004F56D0, cGeneratorDataMessage_GeneratorDataMessageCallback)
