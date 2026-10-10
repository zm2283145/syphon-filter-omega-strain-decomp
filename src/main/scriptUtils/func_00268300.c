#include "types.h"

typedef union { int i; void* p; } ScriptArg;

extern void* GObj_IdentityB(void* p);
extern void Global_SetCallout(void* obj, int label, int text, unsigned char flag);

/* Script native: sets a callout (label, text, flag) on the resolved object. */
int Script_SetCallout_2(ScriptArg* args)
{
    int textArg[1];
    int labelArg[1];
    int text;
    unsigned char on;
    void* obj;
    on = args[3].i != 0;
    textArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    text = *(int*)textArg;
    obj = GObj_IdentityB(args[0].p);
    Global_SetCallout(obj, *(int*)labelArg, text, on);
    return 0;
}
