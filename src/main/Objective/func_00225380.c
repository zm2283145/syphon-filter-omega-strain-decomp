#include "types.h"
#include "scriptUtils_types.h"

typedef struct ObjectiveP {
    char pad00[0x64];
    int pluralString; /* 0x64 */
} ObjectiveP;

extern ObjectiveP* Objective_ResolveReceiver(void* obj);
extern int func_00228B20(ObjectiveP* obj, int text);

/* Script native: cObjective.SetPluralString(text). */
int Script_cObjective_SetPluralString(ScriptArg* args) {
    volatile int textSlot = args[1].i;
    int text = textSlot;
    ObjectiveP* obj = Objective_ResolveReceiver(args[0].p);
    obj->pluralString = func_00228B20(obj, text);
    return 0;
}
