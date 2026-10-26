#include "types.h"

void cLosManager_cCollisionModelList_Game_DeleteRequest(int a0, int a1) {
    int cond;

    cond = a1 == 0;
    if (cond) goto L0013AE10;
    *(char*)((char*)a1 + 32) = 0;
L0013AE10:;
    goto ret;
ret:;
}
