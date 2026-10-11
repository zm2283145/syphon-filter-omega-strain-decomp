#include "types.h"
#include "net_register_type.h"

typedef struct { char a; } Proto_0023F890;
extern char D_004F7C48[];
extern void func_0023F680(void);

NETREG_BEGIN_KEEP(func_0023F890, Proto_0023F890)
NETREG_FIELD(a, 1, 1)
NETREG_END(D_004F7C48, func_0023F680)
