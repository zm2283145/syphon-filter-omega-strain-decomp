/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void func_0016E880(Word*, int);
extern Word* func_001F3620(Word*, int);
extern void func_001F36E0(void);
extern void func_001F36F0(void);

void func_001F3690(Word* self, int a1) {
    Word tmp;

    func_0016E880(&tmp, a1);
    func_001F3620(self, tmp.value);
}

void func_001F36D0(void) {
    func_001F36E0();
}

void func_001F36E0(void) {
    func_001F36F0();
}
