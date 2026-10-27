/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "gameFrontEnd_types.h"

extern char D_005723D0;     /* setup guard byte */
extern int nGlobalization_GetLanguageName_void(void);

void FrontEnd_SetOnlineMode(FeItem* item, int value) {
    D_005723D0 = 0;
    item->unk30 = value;
}

int Loc_GetCurrentLanguageName_Thunk(void) {
    return nGlobalization_GetLanguageName_void();
}
