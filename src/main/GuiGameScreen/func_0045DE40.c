/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern char D_0055A300[];
extern void Pad_ResetHeldMask(void* p);
extern void* Gui_GetScreenStack(void);
extern void GuiScreen_SetFocus(void* gui, int a1);

void func_0045DE40(int a0) {
    GuiScreen_SetFocus(Gui_GetScreenStack(), a0);
    Pad_ResetHeldMask(D_0055A300);
}
