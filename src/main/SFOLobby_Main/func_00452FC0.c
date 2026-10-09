/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "SFOLobby_Main_types.h"

void func_00452FC0(LobbyMain* self, int value) {
    self->unk2550 = value;
}

/* True when the state byte equals 5. */
int func_00452FD0(LobbyMain* self) {
    return self->state == 5;
}

int func_00452FE0(LobbyMain* self) {
    return self->unk2570;
}
