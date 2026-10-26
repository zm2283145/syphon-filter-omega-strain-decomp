/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DBC[];
extern char D_00497DC0[];
extern char D_00497DC4[];

int MediusUniqueCallbackChatToggleResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DBC;
    cond = v0 == 0;
    if (cond) goto L0046DA64;
    v0 = ((int (*)(void))v0)();
L0046DA64:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackTextFilterRequestHandler(void) {
    return 108;
}

int MediusUniqueCallbackTextFilterResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DC0;
    cond = v0 == 0;
    if (cond) goto L0046DA9C;
    v0 = ((int (*)(void))v0)();
L0046DA9C:;
    v0 = 0 + 92;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackReassignGameMediusWorldIDHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DC4;
    cond = v0 == 0;
    if (cond) goto L0046DACC;
    v0 = ((int (*)(void))v0)();
L0046DACC:;
    v0 = 0 + 8;
    goto ret;
ret:
    return v0;
}
