/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern char D_0055A300[];
extern void cJoystick_Debounce(void* p);
extern void* Gui_Canvas(void);
extern void GuiCanvas_SetFocus(void* gui, int a1);

void GuiGameScreen_ReleaseInput(int a0) {
    GuiCanvas_SetFocus(Gui_Canvas(), a0);
    cJoystick_Debounce(D_0055A300);
}
