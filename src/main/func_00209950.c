/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Unk489738* D_00489738;
extern void func_00121B60(void);
extern void func_00123BE8(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);

void func_00209950(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3, float f12, float f13, float f14, float f15, float f16, float f17, float f18, float f19) {
    func_00123BE8(D_00489738->unk0C, a0, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    func_00121B60();
}
