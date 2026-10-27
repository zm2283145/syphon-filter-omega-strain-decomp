#include "types.h"
#include "net_register_type.h"

typedef struct { char a; } Proto_0023F890;
extern char D_004F7C48[];
extern void cNICameraMsg_NICameraCallback(void);

NETREG_BEGIN_KEEP(cNICameraMsg_InitNet, Proto_0023F890)
NETREG_FIELD(a, 1, 1)
NETREG_END(D_004F7C48, cNICameraMsg_NICameraCallback)
