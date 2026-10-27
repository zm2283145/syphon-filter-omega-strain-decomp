#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_00582740;

void StaticInit_NetPlayGameMsg(void) {
    D_00582740 = "NetPlayGameMsg";
}
