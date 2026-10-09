/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern unsigned char D_004F7D40;
extern void Global_SetInfoBarFont(int font);

/* Script native: SetInfoBarFont(font). */
int Script_SetInfoBarFont(ScriptArg* args) {
    Global_SetInfoBarFont((unsigned char)args[0].i);
    return 0;
}

/* Sets the info bar font index (Global_SetInfoBarFont). */
void Global_SetInfoBarFont(int font) {
    D_004F7D40 = font;
}
