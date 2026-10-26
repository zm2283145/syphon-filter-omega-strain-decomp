/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

static const unsigned int dat_00497CB0[1] = { 0x0 };

int MediusUniqueCallbackTicketTranslationRequestHandler(void) {
    return 141;
}

int MediusUniqueCallbackTicketTranslationResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)((char*)dat_00497CB0);
    cond = v0 == 0;
    if (cond) goto L0046DFEC;
    v0 = ((int (*)(void))v0)();
L0046DFEC:;
    v0 = 0 + 564;
    goto ret;
ret:
    return v0;
}
