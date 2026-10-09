/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "SFOLobby_Callback_types.h"

extern LobbyState* D_00585E60;
extern int func_004505C0(void);

/* Lobby callback: unless func_004505C0() reports busy, flags the event and stores
 * value when it is positive. */
void func_00447220(int value) {
    if (func_004505C0() == 0) {
        D_00585E60->unk184 = 1;
        if (value > 0) {
            D_00585E60->unk180 = value;
        }
    }
}
