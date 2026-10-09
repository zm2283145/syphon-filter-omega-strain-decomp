/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "SFOLobby_Lobby_types.h"

extern void func_0044F2E0(void* list, int index);

/* Forwards index to the list at +0x38 when it is within range. */
void func_00450EC0(LobbyLobby* self, int index) {
    if (index < self->count) {
        func_0044F2E0(self->list, index);
    }
}
