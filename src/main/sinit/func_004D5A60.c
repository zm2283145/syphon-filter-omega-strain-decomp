#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_005436B0;

void StaticInit_NextFrameMsgName(void) {
    D_005436B0 = "MSGLIB_NEXTFRAME";
}
