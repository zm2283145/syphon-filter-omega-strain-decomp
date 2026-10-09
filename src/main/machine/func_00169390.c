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
extern int func_004294C0(void);
extern int func_00429D30(void);

/* Per-frame service: flush network messages in multiplayer, then update D_004FFC04. */
void func_00169390(void) {
    if (D_005721C8 != 0) {
        NetMsgThrottle_SendMsg();
        func_00429D30();
    }
    if (D_004FFC04 != 0 && func_004294C0() != 0) {
        func_002CA580(D_004FFC04);
    }
}
