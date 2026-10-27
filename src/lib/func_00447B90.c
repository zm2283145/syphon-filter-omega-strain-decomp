/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int SFOLobby_IgnoreCallbacks(void);

int SFOLobby_Callback_MediusErrorMessage(void) {
    int tmp0;

    tmp0 = SFOLobby_IgnoreCallbacks();
    return tmp0;
}
