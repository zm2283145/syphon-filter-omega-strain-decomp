/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598470[];
extern char D_00598474[];

int MediusUniqueCallbackRespondToClanTeamChallengeResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598470;
    cond = v0 == 0;
    if (cond) goto L0046D604;
    v0 = ((int (*)(void))v0)();
L0046D604:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackRevokeClanTeamChallengeRequestHandler(void) {
    return 44;
}

int MediusUniqueCallbackRevokeClanTeamChallengeResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598474;
    cond = v0 == 0;
    if (cond) goto L0046D63C;
    v0 = ((int (*)(void))v0)();
L0046D63C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
