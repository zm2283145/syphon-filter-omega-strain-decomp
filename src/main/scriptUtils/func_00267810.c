#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

extern void* GObj_IdentityB(void*);
extern void Global_SetPersonalTimer(void*, int, float);

/* Script: SetPersonalTimer(owner, time, id); arguments are staged through the stack. */
int Script_SetPersonalTimer(ScriptArg* args) {
    int id[1];
    int time[1];
    int idValue;
    void* owner;
    id[0] = args[2].i;
    time[0] = args[1].i;
    idValue = *(int*)id;
    owner = GObj_IdentityB(args[0].p);
    Global_SetPersonalTimer(owner, idValue, *(float*)time);
    return 0;
}
