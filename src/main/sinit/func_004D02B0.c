#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_004F80A8;

void func_004D02B0(void) {
    D_004F80A8 = "MSGGAME_RESTORE_BODY_REQUEST";
}
