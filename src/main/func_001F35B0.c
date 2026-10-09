/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void func_0013D890(Word*, int);
extern Word* func_001F2ED0(Word*, Word*);
extern Word* func_001F3620(Word*, int);

Word* func_001F35B0(Word* dst, Word* src) {
    func_001F2ED0(dst, src);
    return dst;
}

void func_001F35E0(Word* self, int a1) {
    Word tmp;

    func_0013D890(&tmp, a1);
    func_001F3620(self, tmp.value);
}

Word* func_001F3620(Word* dst, int value) {
    Word tmp;

    tmp.value = value;
    func_001F2ED0(dst, &tmp);
    return dst;
}
