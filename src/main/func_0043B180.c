/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00439670(void);

void func_0043B180(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int func_0043B190(int a0) {
    func_00439670();
    return a0;
}
