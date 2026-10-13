#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
/* True when no lobby instance exists; every reply callback checks this first. */
int SFOLobby_NoInstance(void)
{
    return D_00585E60 == 0;
}
