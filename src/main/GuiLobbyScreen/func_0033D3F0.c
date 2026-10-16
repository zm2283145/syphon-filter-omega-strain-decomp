/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiLobbyScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004B99C8[];
static void * const dat_004928A8[2] = { (void*)D_004B99C8, (void*)0x0 };
extern int GuiWidget_FindChildByName(void* self, int a1);
extern int func_0041F150(void* self);

void GuiScreen_Init(char* self) {
    func_0041F150(self);
    *(int*)(self + 124) = GuiWidget_FindChildByName(self, (*(int*)dat_004928A8));
}
