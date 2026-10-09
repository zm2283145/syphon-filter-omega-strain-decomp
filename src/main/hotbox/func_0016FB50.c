/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

int Script_cHotbox_Occupied(HotboxScriptArg* args) {
    return 0 < ((cHotbox*)args[0].p)->occupants;
}

int Script_cHotbox_ClearInteractMessage(HotboxScriptArg* args) {
    ((cHotbox*)args[0].p)->interactMessage = 0;
    return 0;
}
