#include "types.h"

extern void Objective_ResolveReceiver(int handle);

/* Script native: Objective.SetMaxOwners - resolves the receiver object. */
int Objective_ScriptSetMaxOwners(int* args) {
    Objective_ResolveReceiver(args[0]);
    return 0;
}
