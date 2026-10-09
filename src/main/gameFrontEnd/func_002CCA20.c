/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "gameFrontEnd_types.h"

extern char D_005723D0;     /* setup guard byte */
extern int Loc_GetCurrentLanguageName(void);

void func_002CCA20(FeItem* item, int value) {
    D_005723D0 = 0;
    item->unk30 = value;
}

int func_002CCA30(void) {
    return Loc_GetCurrentLanguageName();
}
