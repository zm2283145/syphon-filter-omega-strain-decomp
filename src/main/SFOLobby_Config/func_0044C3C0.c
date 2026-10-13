#include "SFOLobby.h"

extern void LobbyArray_Free(LobbyArray* p);
extern void func_00452FC0(SFOLobby* self, int a);

/* Leaves the NETWORK state (1) for IDLE (9), releasing netConfigList. */
void SFOLobby_LeaveNetworkState(SFOLobby* self)
{
    if (self->state != SFOLOBBY_STATE_IDLE && self->state == SFOLOBBY_STATE_NETWORK) {
        self->state = SFOLOBBY_STATE_IDLE;
        if (self->netConfigList) {
            LobbyArray_Free(self->netConfigList);
        }
        self->netConfigList = 0;
        func_00452FC0(self, 0);
    }
}
