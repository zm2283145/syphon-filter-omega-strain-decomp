#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

typedef struct Objective {
    char pad[0x60];
    int menuString;
} Objective;

extern Objective* Objective_ResolveReceiver(void*);
extern int func_00228B20(Objective*, int);

/* Script: cObjective.SetMenuString(string). */
int Script_cObjective_SetMenuString(ScriptArg* args) {
    volatile int str = args[1].i;
    int s = str;
    Objective* obj = Objective_ResolveReceiver(args[0].p);
    obj->menuString = func_00228B20(obj, s);
    return 0;
}
