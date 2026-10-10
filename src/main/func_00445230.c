#include "SFOLobby_Callback_types.h"

extern unsigned char D_00584237;
extern unsigned char D_00584238;

/* Record callback completion separately from its success status. */
void func_00445230(int unused0, int unused1, int unused2, LobbyStatusResult* result)
{
    D_00584237 = 1;
    if (!result->status)
        D_00584238 = 1;
    else
        D_00584238 = 0;
}
