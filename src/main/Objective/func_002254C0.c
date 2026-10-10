#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char pad[0x70]; int addString; } Objective;
extern Objective* Objective_ResolveReceiver(void* object);
extern int func_00228B20(Objective* objective, int text);

/* Script native: sets the objective's "add" string from args[1]; returns 0. */
int Script_cObjective_SetAddString(ScriptArg* args)
{
    volatile int text = args[1].i;
    int value = text;
    Objective* objective = Objective_ResolveReceiver(args[0].p);
    objective->addString = func_00228B20(objective, value);
    return 0;
}
