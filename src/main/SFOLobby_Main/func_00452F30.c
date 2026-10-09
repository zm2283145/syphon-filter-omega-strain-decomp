/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "SFOLobby_Main_types.h"

/* Invokes the registered callback, if any, with (a0, a1). */
void func_00452F30(LobbyMain* self, int a0, int a1) {
    LobbyMainCallback cb = self->callback;
    if (cb != 0) {
        cb(a0, a1);
    }
}

/* Registers the callback used by func_00452F30. */
void func_00452F60(LobbyMain* self, LobbyMainCallback cb) {
    self->callback = cb;
}
