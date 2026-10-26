/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598480[];
extern char D_00598484[];

int MediusUniqueCallbackConfirmClanTeamChallengeResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598480;
    cond = v0 == 0;
    if (cond) goto L0046D6E4;
    v0 = ((int (*)(void))v0)();
L0046D6E4:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackGetAllClanMessagesRequestHandler(void) {
    return 48;
}

int MediusUniqueCallbackGetAllClanMessagesResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598484;
    cond = v0 == 0;
    if (cond) goto L0046D71C;
    v0 = ((int (*)(void))v0)();
L0046D71C:;
    v0 = 0 + 240;
    goto ret;
ret:
    return v0;
}
