/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* func_001F2ED0(Word*, Word*);

Word* func_001F2F20(Word* dst, int value) {
    Word tmp;

    tmp.value = value;
    func_001F2ED0(dst, &tmp);
    return dst;
}
