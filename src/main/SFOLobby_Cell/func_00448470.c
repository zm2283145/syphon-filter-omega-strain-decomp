#include "loose05_types.h"

extern int func_004505C0(void);
extern SFOLobby* D_00585E60;

/* Mark the pending cell event when the lobby gate returns zero. */
void func_00448470(void)
{
    if (!func_004505C0())
        D_00585E60->unk21C = 1;
}
