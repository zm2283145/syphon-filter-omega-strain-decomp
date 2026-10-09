/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004AC7F0[];   /* "GuiEquipmentModify" */
extern int func_0027C4D8(void);

int func_002BCAF0(void) {
    func_0027C4D8();
    return 0;
}

/* Class name getter: "GuiEquipmentModify". */
char* func_002BCB10(void) {
    return D_004AC7F0;
}
