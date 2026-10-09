/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int D_00506390;
extern int func_0028D870(int);

Rel* func_00290B90(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Word* func_00290BB0(Word* self, int value) {
    self->value = value;
    return self;
}

int func_00290BC0(void) {
    return func_0028D870(D_00506390);
}
