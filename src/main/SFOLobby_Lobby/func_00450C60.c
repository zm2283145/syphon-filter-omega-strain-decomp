#include "SFOLobby.h"
#pragma mpwc_relax on
int func_00450CF0();
int SFOLobby_RequestAccountInfo(SFOLobby *, int);
void *memcpy(void *, void *, int);
/* Gets the player info for an account: from the cache when fresh, else by asking
 * the server (SFOLobby_RequestAccountInfo). */
int func_00450C60(SFOLobby *self, int id, LobbyPlayerInfo *out) {
    if (func_00450CF0() != 0) {
        return 1;
    }
    if (SFOLobby_RequestAccountInfo(self, id) == 0) {
        return 0;
    }
    memcpy(out, &self->accountInfoReply.info, 0xFC);
    return 1;
}
