/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiLobbyScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004928A8;
extern int func_0041DB80(void* self, int a1);
extern int func_0041F150(void* self);

void func_0033D3F0(char* self) {
    func_0041F150(self);
    *(int*)(self + 124) = func_0041DB80(self, D_004928A8);
}
