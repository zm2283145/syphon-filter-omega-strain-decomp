/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D70[];
extern char D_00497D74[];

int MediusUniqueCallbackAddToBuddyListConfirmationRequestHandler0(void) {
    return 44;
}

int MediusUniqueCallbackAddToBuddyListConfirmationResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D74;
    cond = v0 == 0;
    if (cond) goto L0046CFFC;
    v0 = ((int (*)(void))v0)();
L0046CFFC:;
    v0 = 0 + 64;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackAddToBuddyListFwdConfirmationRequestHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D70;
    cond = v0 == 0;
    if (cond) goto L0046D02C;
    v0 = ((int (*)(void))v0)();
L0046D02C:;
    v0 = 0 + 64;
    goto ret;
ret:
    return v0;
}
