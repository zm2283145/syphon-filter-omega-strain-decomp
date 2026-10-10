#include "types.h"
#include "scriptUtils_types.h"

typedef struct cHotboxM {
    char pad00[0xA0];
    void* interactMessage; /* 0xA0 */
} cHotboxM;

extern void* Loc_LookupText(int id);

/* Script native: cHotbox.SetInteractMessage(textId). */
int Script_cHotbox_SetInteractMessage(ScriptArg* args) {
    volatile int id = args[1].i;
    cHotboxM* hotbox = args[0].p;
    hotbox->interactMessage = Loc_LookupText(id);
    return 0;
}
