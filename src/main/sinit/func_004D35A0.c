#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0051F068;

void StaticInit_NetGeneratorDeleteMsgName(void) {
    D_0051F068 = "MSGGAME_NET_GENERATORDELETE_REQUEST";
}
