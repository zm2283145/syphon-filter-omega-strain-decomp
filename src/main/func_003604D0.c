/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo class-name getter (vtable D_004DF350 slot 19).
 */

#include "loose03_types.h"

extern char D_004BBC18[];       /* "GuiAgentInfo" */

/* Returns the class name string "GuiAgentInfo". */
const char* GuiAgentInfo_GetClassName(void) {
    return D_004BBC18;
}
