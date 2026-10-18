#include "types.h"

extern void IeElement_Release(int);

void IeScreen_RemoveElementIfSet(int a0) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L00272298;
    IeElement_Release(a0);
L00272298:;
    goto ret;
ret:;
}
