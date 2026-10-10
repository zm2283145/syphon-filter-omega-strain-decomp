#include "types.h"

typedef struct { char pad[0x26]; unsigned char type; } Objective;
typedef union { int i; unsigned char b; void* p; } ScriptArg;

extern Objective* Objective_ResolveReceiver(void* p);

/* Script native: sets the objective's type byte. */
int Script_cObjective_SetType(ScriptArg* args)
{
    unsigned char type = args[1].b;
    Objective_ResolveReceiver(args[0].p)->type = type;
    return 0;
}
