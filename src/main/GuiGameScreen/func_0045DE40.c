/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055A300[];
extern void func_0036A240(int);
extern int func_004147A0(void);
extern void func_00414B30(int, int);

void func_0045DE40(int a0) {
    int tmp0;

    tmp0 = func_004147A0();
    func_00414B30(tmp0, a0);
    func_0036A240((int)D_0055A300);
}
