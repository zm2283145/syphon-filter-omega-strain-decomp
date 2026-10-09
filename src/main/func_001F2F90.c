/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void func_0016E880(Word*, int);
extern Word* func_001F2F20(Word*, int);
extern void func_001F2FE0(void);
extern void func_001F2FF0(void);

void func_001F2F90(Word* self, int a1) {
    Word tmp;

    func_0016E880(&tmp, a1);
    func_001F2F20(self, tmp.value);
}

void func_001F2FD0(void) {
    func_001F2FE0();
}

void func_001F2FE0(void) {
    func_001F2FF0();
}
