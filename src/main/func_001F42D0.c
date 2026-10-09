/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void func_0016E880(Word*, int);
extern Word* func_001F4260(Word*, int);
extern void func_001F4320(void);
extern void func_001F4330(void);

void func_001F42D0(Word* self, int a1) {
    Word tmp;

    func_0016E880(&tmp, a1);
    func_001F4260(self, tmp.value);
}

void func_001F4310(void) {
    func_001F4320();
}

void func_001F4320(void) {
    func_001F4330();
}
