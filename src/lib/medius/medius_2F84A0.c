#include "types.h"

extern int GetKeyMaster(int);

void KM_SetLocalClientID(int a0, int a1) {
    int s0, v0;

    s0 = a1;
    v0 = GetKeyMaster(a0);
    if (v0 != 0) {
    *(int*)((char*)v0 + 20) = s0;
    goto L002F84BC;
    }
L002F84BC:;
    goto ret;
ret:;
}
