#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

extern void Objective_AddGlobal(int);

/* Script native: adds an objective by id. */
int Game_AddObjective(ScriptArg* args) {
    volatile int id = args[0].i;
    Objective_AddGlobal(id);
    return 0;
}
