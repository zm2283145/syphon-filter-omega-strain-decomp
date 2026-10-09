/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern void Global_PlayXA(int track, int a1);

/* Script native: PlayXA(track). */
int Script_PlayXA(ScriptArg* args) {
    int track[1];

    track[0] = args[0].i;
    Global_PlayXA(STACK_COPY(track), 0);
    return 0;
}
