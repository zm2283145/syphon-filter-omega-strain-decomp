/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern void func_00244EE0(void* p, int a1, float f);

/* Forwards to the member at +0x6C4. */
void func_00245800(char* self, int a1, float f) {
    func_00244EE0(self + 1732, a1, f);
}
