#include "loose05_types.h"

extern int SFOLobby_NoInstance(void);
extern SFOLobby* D_00585E60;

/* Mark the pending cell event when the lobby gate returns zero. */
void func_00448470(void)
{
    if (!SFOLobby_NoInstance())
        D_00585E60->gotReply21C = 1;
}
