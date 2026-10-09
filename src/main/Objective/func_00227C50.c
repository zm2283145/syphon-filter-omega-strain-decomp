/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC2C[];
extern void Hud_PostNotification(int, int);

void ObjMan_Notify(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    Hud_PostNotification(tmp0, a1);
}
