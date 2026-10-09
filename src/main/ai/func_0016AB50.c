/*
 * Matched functions (byte-identical with the retail executable).
 * cAI script-native bindings. args[0] is the cAI receiver.
 */

#include "types.h"
#include "ai_types.h"

extern int GObj_IdentityA(AIGObj*);

/* Stores the elapsed time (args[1]) on the AI; volatile mirrors the original stack temporary. */
int Script_cAI_SendTimeElapsedMessage(AIScriptArg* args) {
    volatile int bits = args[1].i;
    ((cAI*)args[0].p)->timeElapsed = *(float*)&bits;
    return 0;
}

int Script_GetGOBJ_AI(AIScriptArg* args) {
    return GObj_IdentityA(((cAI*)args[0].p)->gobj);
}

int Script_cAI_IsVisible(AIScriptArg* args) {
    return ((cAI*)args[0].p)->gobj->unk38 != 0x80;
}
