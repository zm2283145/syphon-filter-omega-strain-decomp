/*
 * Matched functions (byte-identical with the retail executable).
 * GuiDossiers class-name getter (vtable D_004DEC30 slot 19).
 */

#include "loose03_types.h"

extern char D_004BA650[];       /* "GuiDossiers" */

/* Returns the class name string "GuiDossiers". */
const char* GuiDossiers_GetClassName(void) {
    return D_004BA650;
}
