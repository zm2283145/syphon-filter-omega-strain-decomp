/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D84[];

int MediusUniqueCallbackGetPolicyResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D84;
    cond = v0 == 0;
    if (cond) goto L0046D124;
    v0 = ((int (*)(void))v0)();
L0046D124:;
    v0 = 0 + 288;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackUpdateUserStateHandler(void) {
    return 24;
}
