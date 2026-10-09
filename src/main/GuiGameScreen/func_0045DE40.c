/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern char D_0055A300[];
extern void func_0036A240(void* p);
extern void* func_004147A0(void);
extern void func_00414B30(void* gui, int a1);

void func_0045DE40(int a0) {
    func_00414B30(func_004147A0(), a0);
    func_0036A240(D_0055A300);
}
