#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0052ACB0;

void StaticInit_NetScoreMsg(void) {
    D_0052ACB0 = "NetScoreMsg";
}
