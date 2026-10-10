#include "types.h"
#include "scriptUtils_types.h"

extern void* ObjMan_ResolveReceiver(void* obj);
extern void ObjMan_Notify(void* man, int text);

/* Script native: cObjectiveMan.SetDisplayString(man, text). */
int Script_cObjectiveMan_SetDisplayString(ScriptArg* args) {
    int part[1]; /* staged through the stack */
    part[0] = args[1].i;
    ObjMan_Notify(ObjMan_ResolveReceiver(args[0].p), *(int*)part);
    return 0;
}
