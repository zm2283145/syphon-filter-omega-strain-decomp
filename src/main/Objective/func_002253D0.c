#include "types.h"

typedef struct { char pad[0x68]; int string; } Objective;
typedef union { int i; void* p; } ScriptArg;

extern Objective* Objective_ResolveReceiver(void* p);
extern int func_00228B20(Objective* obj, int str);

/* Script native: sets the objective's single string. */
int Script_cObjective_SetSingleString(ScriptArg* args)
{
    int strArg[1];
    int str;
    Objective* obj;
    strArg[0] = args[1].i;
    str = *(int*)strArg;
    obj = Objective_ResolveReceiver(args[0].p);
    obj->string = func_00228B20(obj, str);
    return 0;
}
