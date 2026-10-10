#include "types.h"
typedef struct { char pad[0x4C]; int name; } Objective002255B0;
extern Objective002255B0* Objective_ResolveReceiver(int handle);
extern int func_00228B20(Objective002255B0* obj, int name);
/* Script: cObjective.SetName(name). */
int Script_cObjective_SetName(int* args)
{
    volatile int name = args[1]; /* staged through the stack */
    Objective002255B0* obj;
    int n = name;
    obj = Objective_ResolveReceiver(args[0]);
    obj->name = func_00228B20(obj, n);
    return 0;
}
