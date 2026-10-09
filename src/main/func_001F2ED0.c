/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void func_0013D890(Word*, int);
extern Word* func_001F2F20(Word*, int);

Word* func_001F2ED0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001F2EE0(Word* self, int a1) {
    Word tmp;

    func_0013D890(&tmp, a1);
    func_001F2F20(self, tmp.value);
}
