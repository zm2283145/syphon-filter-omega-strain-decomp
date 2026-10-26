/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int D_00497CB4 = 0;
int D_00497CB8 = 0;

int MediusUniqueCallbackTicketListResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)((char*)&D_00497CB4);
    cond = v0 == 0;
    if (cond) goto L0046E024;
    v0 = ((int (*)(void))v0)();
L0046E024:;
    v0 = 0 + 564;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackTicketItemRequestHandler(void) {
    return 56;
}

int MediusUniqueCallbackTicketItemResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)((char*)&D_00497CB8);
    cond = v0 == 0;
    if (cond) goto L0046E05C;
    v0 = ((int (*)(void))v0)();
L0046E05C:;
    v0 = 0 + 1232;
    goto ret;
ret:
    return v0;
}
