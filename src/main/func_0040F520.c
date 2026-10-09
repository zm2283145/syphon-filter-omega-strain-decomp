/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00571CD0[];
extern void func_0040FB60(int);

void Tree_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

void Tree_Begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

void func_0040F540(void) {
    int a0;
    int cond;

    a0 = *(int*)(char*)D_00571CD0;
    cond = a0 == 0;
    if (cond) goto L0040F560;
    func_0040FB60(a0);
L0040F560:;
    goto ret;
ret:;
}
