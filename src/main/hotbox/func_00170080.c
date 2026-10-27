#include "types.h"
#include "net_register_type.h"
typedef struct { int a; int b; int c; int d; } Proto_0080;
extern char D_004EE6A0[];
extern void* cHotboxMsg_HotBoxMsgCallback(void);
NETREG_BEGIN_KEEP(cHotboxMsg_InitNet, Proto_0080)
    NETREG_FIELD(a, 4, 1)
    NETREG_FIELD(b, 4, 1)
    NETREG_FIELD(d, 4, 1)
    NETREG_FIELD(c, 4, 1)
NETREG_END(D_004EE6A0, cHotboxMsg_HotBoxMsgCallback)