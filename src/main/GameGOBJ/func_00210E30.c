#include "types.h"

typedef union { int i; void* p; } ScriptArg;

extern void cElevatorGOBJ_SetFloorName(void* elevator, int floor, int name);

/* Script native: sets the name of an elevator floor. */
int Script_cElevatorGOBJ_SetFloorName(ScriptArg* args)
{
    int name[1];
    int floor[1];
    name[0] = args[2].i;
    floor[0] = args[1].i;
    cElevatorGOBJ_SetFloorName(args[0].p, *(int*)floor, *(int*)name);
    return 0;
}
