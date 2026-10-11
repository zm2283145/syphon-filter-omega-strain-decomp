#include "types.h"

typedef union { int i; void* p; } ScriptArg;

extern void* func_0014A690(void* p);
extern void Global_SetCallout_2(void* obj, int label, int text, int flag);

/* Script native: sets the label of a callout on the resolved object. */
int Script_SetCallout_3(ScriptArg* args)
{
    int labelArg[1];
    int textArg[1];
    int text;
    void* obj;
    textArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    text = *(int*)textArg;
    obj = func_0014A690(args[0].p);
    Global_SetCallout_2(obj, *(int*)labelArg, text, 0);
    return 0;
}
