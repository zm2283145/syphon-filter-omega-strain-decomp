#include "SFOLobby.h"

extern int SFOLobby_NoInstance(void);
extern SFOLobby* D_00585E60;

/* Reply callback: flags gotReply230. */
void func_004466B0(void)
{
    if (!SFOLobby_NoInstance())
        D_00585E60->gotReply230 = 1;
}
