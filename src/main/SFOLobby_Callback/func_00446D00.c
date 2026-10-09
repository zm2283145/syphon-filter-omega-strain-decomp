/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "SFOLobby_Callback_types.h"

extern LobbyState* D_00585E60;
extern int String_Copy(char* dst, char* src);
extern int func_004505C0(void);

/* Lobby callback: unless func_004505C0() reports busy, flags the event and copies
 * the info name into the lobby state when info->unk2C is 0. */
void func_00446D00(int a0, int a1, int a2, LobbyCallbackInfo* info) {
    if (func_004505C0() == 0) {
        D_00585E60->unk204 = 1;
        if (info->unk2C == 0) {
            String_Copy(D_00585E60->name, info->name);
        }
    }
}
