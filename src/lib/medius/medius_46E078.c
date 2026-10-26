/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int D_00497CBC = 0;
extern char D_005984A0[];

int MediusUniqueCallbackTicketEventResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)((char*)&D_00497CBC);
    cond = v0 == 0;
    if (cond) goto L0046E094;
    v0 = ((int (*)(void))v0)();
L0046E094:;
    v0 = 0 + 396;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackFileCreateRequestHandler(void) {
    return 472;
}

int MediusUniqueCallbackFileCreateResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984A0;
    cond = v0 == 0;
    if (cond) goto L0046E0CC;
    v0 = ((int (*)(void))v0)();
L0046E0CC:;
    v0 = 0 + 200;
    goto ret;
ret:
    return v0;
}
