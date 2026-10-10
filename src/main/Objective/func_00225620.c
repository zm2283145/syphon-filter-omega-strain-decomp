#include "types.h"
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char pad[0x48]; int achievementId; } Objective;
extern Objective* Objective_ResolveReceiver(void* object);
/* Script native: sets objective args[0]'s achievement id to args[1]; returns 0. */
int Script_cObjective_SetAchievementID(ScriptArg* args)
{
    volatile int id = args[1].i;
    int value = id;
    Objective_ResolveReceiver(args[0].p)->achievementId = value;
    return 0;
}
