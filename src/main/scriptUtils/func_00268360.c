#include "types.h"

typedef union { int i; void* p; } ScriptArg;

extern void* GObj_IdentityB(void* p);
extern void Global_SetCallout(void* obj, int label, int text, int flag);

/* Script native: sets the label of a callout on the resolved object. */
int Script_SetCallout(ScriptArg* args)
{
    int textArg[1];
    int labelArg[1];
    int text;
    void* obj;
    textArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    text = *(int*)textArg;
    obj = GObj_IdentityB(args[0].p);
    Global_SetCallout(obj, *(int*)labelArg, text, 0);
    return 0;
}
