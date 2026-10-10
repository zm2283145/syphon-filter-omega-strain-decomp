#include "types.h"
extern void* Objective_ResolveReceiver(int handle);
extern void cObjective_Add(void* objective);
/* Script: cObjective.Add(). */
int Script_cObjective_Add(int* args)
{
    cObjective_Add(Objective_ResolveReceiver(args[0]));
    return 0;
}
