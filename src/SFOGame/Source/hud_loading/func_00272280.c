#include "types.h"

extern void cInterfaceElement_Destroy(int);

void DestroyElement(int a0) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L00272298;
    cInterfaceElement_Destroy(a0);
L00272298:;
    goto ret;
ret:;
}
