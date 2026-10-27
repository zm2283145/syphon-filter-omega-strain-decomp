#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0052ACC8;

void StaticInit_NetWeaponMsg(void) {
    D_0052ACC8 = "MSGGAME_NET_WEAPON_MESSAGE";
}
