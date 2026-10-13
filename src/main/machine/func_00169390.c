/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void* D_004FFC04;
extern unsigned char D_005721C8;    /* nonzero in a multiplayer game */
extern int NetMsgThrottle_SendMsg(void);
extern void func_002CA580(void* obj);
extern int DME_GetLobby(void);
extern int DME_Update(void);

/* Per-frame service: flush network messages in multiplayer, then update D_004FFC04. */
void func_00169390(void) {
    if (D_005721C8 != 0) {
        NetMsgThrottle_SendMsg();
        DME_Update();
    }
    if (D_004FFC04 != 0 && DME_GetLobby() != 0) {
        func_002CA580(D_004FFC04);
    }
}
