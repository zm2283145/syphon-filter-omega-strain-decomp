/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F5000[];
extern void func_00100440(int, int, int, int);
extern int func_001E5480(int, int);

void* func_001EEBA0(char* self) {
    return self + 8;
}

void func_001EEBB0(void) {
    func_00100440((int)D_004F5000, (int)func_001E5480, 112, 7);
}
