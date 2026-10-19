#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_00583990;

void StaticInit_NetTransferRecvMsgName(void) {
    D_00583990 = "NetTransferRecvMsg";
}
