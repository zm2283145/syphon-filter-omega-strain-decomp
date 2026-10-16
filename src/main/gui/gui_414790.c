/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int D_00571FB0;
extern int D_00571FB8;

int Gui_GetScreenList(void) {
    return D_00571FB8;
}

int Gui_GetScreenStack(void) {
    return D_00571FB0;
}
