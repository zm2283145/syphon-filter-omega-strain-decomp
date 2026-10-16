/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern void HudTimer_Start(void* p, int a1, float f);

/* Forwards to the member at +0x6C4. */
void func_00245800(char* self, int a1, float f) {
    HudTimer_Start(self + 1732, a1, f);
}
