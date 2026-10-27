/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void* D_004FFC04;
extern unsigned char g_IsMultiplayer;    /* nonzero in a multiplayer game */
extern int cNetMsgThrottle_NextFrame(void);
extern void cGameFrontEnd_LobbyUpdate(void* obj);
extern int cDME_GetLobby(void);
extern int DME_Update(void);

/* Per-frame service: flush network messages in multiplayer, then update D_004FFC04. */
void cMachine_NetUpdate(void) {
    if (g_IsMultiplayer != 0) {
        cNetMsgThrottle_NextFrame();
        DME_Update();
    }
    if (D_004FFC04 != 0 && cDME_GetLobby() != 0) {
        cGameFrontEnd_LobbyUpdate(D_004FFC04);
    }
}
