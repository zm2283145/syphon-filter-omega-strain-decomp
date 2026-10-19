#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0051EE68;

void StaticInit_NetCreateBlastMsgName(void) {
    D_0051EE68 = "NetCreateBlastMsg";
}
