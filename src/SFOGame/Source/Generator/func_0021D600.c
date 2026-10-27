#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; short c; } Proto_0021D600;
extern char D_004F56C8[];
extern void cGeneratorMessageBase_GeneratorMessageBaseCallback(void);

NETREG_BEGIN_KEEP(cGeneratorMessageBase_InitNet, Proto_0021D600)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 2, 1)
NETREG_END(D_004F56C8, cGeneratorMessageBase_GeneratorMessageBaseCallback)
