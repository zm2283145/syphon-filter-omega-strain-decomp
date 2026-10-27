#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0052ACC0;

void StaticInit_NetShatterMsg(void) {
    D_0052ACC0 = "NetShatterMsg";
}
