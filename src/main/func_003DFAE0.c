/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003DFB20(void);

Word* func_003DFAE0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003DFAF0(Iter* out, Tree* t) {
    out->p = &t->header;
}

int Script_ClearSchedules(void) {
    func_003DFB20();
    return 0;
}
