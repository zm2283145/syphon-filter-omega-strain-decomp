#include "types.h"

typedef struct ObjectiveMap {
    char pad[0x6C];
    int mapString;
} ObjectiveMap;

typedef struct ScriptArgs2 {
    int obj;
    int arg1;
} ScriptArgs2;

extern ObjectiveMap* Objective_ResolveReceiver(int handle);
extern int func_00228B20(ObjectiveMap* obj, int str);

/* Script native: cObjective.SetMapString(string). */
int Script_cObjective_SetMapString(ScriptArgs2* args) {
    volatile int arg = args->arg1;
    int str = arg;
    ObjectiveMap* obj = Objective_ResolveReceiver(args->obj);
    obj->mapString = func_00228B20(obj, str);
    return 0;
}
