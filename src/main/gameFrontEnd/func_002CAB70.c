/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "gameFrontEnd_types.h"

/* True when the screen has a widget with flag bit 3 set. */
int func_002CAB70(FeScreen* screen) {
    FeWidget* w = screen->widget;

    if (w != 0) {
        return 0u < (unsigned int)(w->flags & 8);
    }
    return 0;
}
