#include "loose05_types.h"

extern int func_004505C0(void);
extern SFOLobby* D_00585E60;

/* Mark the pending lobby event when the lobby gate returns zero. */
void func_004466B0(void)
{
    if (!func_004505C0())
        D_00585E60->unk230 = 1;
}
