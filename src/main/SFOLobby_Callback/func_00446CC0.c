#include "SFOLobby.h"
extern int SFOLobby_NoInstance(void);
extern SFOLobby* D_00585E60;
/* Reply callback: flags gotReply208 (awaited by func_004505E0). */
void func_00446CC0(void)
{
    if (!SFOLobby_NoInstance())
        D_00585E60->gotReply208 = 1;
}
