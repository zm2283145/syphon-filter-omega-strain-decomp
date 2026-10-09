/*
 * Matched functions (byte-identical with the retail executable).
 * Script-native bindings for the cObjective script type. Each callback receives
 * the script argument block; args[0] is the objective receiver.
 */

#include "types.h"
#include "Objective_types.h"

extern int GObj_IdentityB(int);
extern int Objective_Activate(cObjective*);
extern int Objective_Deactivate(cObjective*);
extern cObjective* Objective_ResolveReceiver(void*);
extern int cObjective_ClearMapObject(cObjective*, int);
extern int cObjective_SetAddLabel(cObjective*, int, int);
extern int cObjective_SetCompleteLabel(cObjective*, int, int);
extern int cObjective_SetFailLabel(cObjective*, int, int);
extern int cObjective_SetMapLabel(cObjective*, int, int);
extern int cObjective_SetMapObject(cObjective*, int, int, int);
extern int cObjective_SetMenuLabel(cObjective*, int, int);
extern int cObjective_SetNameLabel(cObjective*, int, int);
extern int cObjective_SetPluralLabel(cObjective*, int, int);
extern int cObjective_SetSingleLabel(cObjective*, int, int);

/* ClearMapObject(bool) */
int Script_cObjective_ClearMapObject_2(ScriptArg* args) {
    cObjective* obj = Objective_ResolveReceiver(args[0].p);
    cObjective_ClearMapObject(obj, args[1].i != 0);
    return 0;
}

int Script_cObjective_ClearMapObject(ScriptArg* args) {
    cObjective_ClearMapObject(Objective_ResolveReceiver(args[0].p), 0);
    return 0;
}

/* SetMapObject(gobj, int); volatile locals mirror the original stack temporaries. */
int Script_cObjective_SetMapObject_2(ScriptArg* args) {
    volatile int arg2 = args[2].i;
    cObjective* obj = Objective_ResolveReceiver(args[0].p);
    int gobj = GObj_IdentityB(args[1].i);
    cObjective_SetMapObject(obj, gobj, arg2, 0);
    return 0;
}

int Script_cObjective_SetMapObject(ScriptArg* args) {
    cObjective* obj = Objective_ResolveReceiver(args[0].p);
    cObjective_SetMapObject(obj, GObj_IdentityB(args[1].i), 0, 0);
    return 0;
}

int Objective_ScriptDeactivate(ScriptArg* args) {
    Objective_Deactivate(Objective_ResolveReceiver(args[0].p));
    return 0;
}

int Objective_ScriptActivate(ScriptArg* args) {
    Objective_Activate(Objective_ResolveReceiver(args[0].p));
    return 0;
}

int Script_cObjective_IsActive(ScriptArg* args) {
    return Objective_ResolveReceiver(args[0].p)->active;
}

int Script_Objective_WasFailed(ScriptArg* args) {
    return Objective_ResolveReceiver(args[0].p)->state == OBJECTIVE_FAILED;
}

int Script_Objective_IsComplete(ScriptArg* args) {
    return Objective_ResolveReceiver(args[0].p)->state == OBJECTIVE_COMPLETE;
}

int Script_cObjective_SetState(ScriptArg* args) {
    unsigned char state = args[1].u8;
    Objective_ResolveReceiver(args[0].p)->state = state;
    return 0;
}

int Script_cObjective_GetState(ScriptArg* args) {
    return (unsigned char)Objective_ResolveReceiver(args[0].p)->state;
}

int Script_cObjective_SetPluralLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetPluralLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetSingleLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetSingleLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetFailLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetFailLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetCompleteLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetCompleteLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetAddLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetAddLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetMapLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetMapLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetMenuLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetMenuLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}

int Script_cObjective_SetNameLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    cObjective_SetNameLabel(Objective_ResolveReceiver(args[0].p), label, 0);
    return 0;
}
