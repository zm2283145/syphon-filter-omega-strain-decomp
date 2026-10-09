/*
 * Matched functions (byte-identical with the retail executable).
 * cObjectiveMan script-native bindings: stage control, success/failure and
 * objective lookup. args[0] is the manager receiver.
 */

#include "types.h"
#include "Objective_types.h"

extern int GObj_IdentityB(int);
extern cObjective* ObjMan_GetObjective(cObjectiveMan*, int);
extern int ObjMan_StartStage(cObjectiveMan*, int, int);
extern int Objective_Fail(cObjectiveMan*, cObjective*, int);
extern cObjective* Objective_ResolveReceiver(void*);
extern int Objective_Succeed(cObjectiveMan*, cObjective*, int);
extern int cObjectiveMan_SetPartialSuccess(cObjectiveMan*, cObjective*, int);
extern int cObjectiveMan_SucceedPart(cObjectiveMan*, cObjective*);
extern int func_00225770(cObjective*);
extern cObjectiveMan* ObjMan_ResolveReceiver(void*);

int Script_cObjectiveMan_GetStage(ScriptArg* args) {
    volatile int stage = ObjMan_ResolveReceiver(args[0].p)->stage;
    return stage;
}

int ObjMan_ScriptStartStage(ScriptArg* args) {
    volatile int stage = args[1].i;
    ObjMan_StartStage(ObjMan_ResolveReceiver(args[0].p), stage, 0);
    return 0;
}

/* Fail(objective, gobj) */
int Script_cObjectiveMan_Fail(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    Objective_Fail(mgr, Objective_ResolveReceiver(args[1].p), GObj_IdentityB(args[2].i));
    return 0;
}

/* Fail(objective) */
int Script_Objective_Fail(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    Objective_Fail(mgr, Objective_ResolveReceiver(args[1].p), 0);
    return 0;
}

int Script_cObjectiveMan_SetPartialSuccess(ScriptArg* args) {
    volatile int value = args[2].i;
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    cObjective* obj = Objective_ResolveReceiver(args[1].p);
    cObjectiveMan_SetPartialSuccess(mgr, obj, value);
    return 0;
}

int Script_cObjectiveMan_SucceedPart(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    cObjectiveMan_SucceedPart(mgr, Objective_ResolveReceiver(args[1].p));
    return 0;
}

/* Succeed(objective, gobj) */
int Script_cObjectiveMan_Succeed(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    Objective_Succeed(mgr, Objective_ResolveReceiver(args[1].p), GObj_IdentityB(args[2].i));
    return 0;
}

/* Succeed(objective) */
int Script_Objective_Succeed(ScriptArg* args) {
    cObjectiveMan* mgr = ObjMan_ResolveReceiver(args[0].p);
    Objective_Succeed(mgr, Objective_ResolveReceiver(args[1].p), 0);
    return 0;
}

/* GetObjective(id): null when no objective has that ID. */
int Script_GetObjective(ScriptArg* args) {
    volatile int id = args[1].i;
    return func_00225770(ObjMan_GetObjective(ObjMan_ResolveReceiver(args[0].p), id));
}
