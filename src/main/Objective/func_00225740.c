/*
 * Matched functions (byte-identical with the retail executable).
 * cObjective script-type registration helpers and cObjectiveMan script-native
 * bindings (args[0] is the manager receiver).
 */

#include "types.h"
#include "Objective_types.h"

extern char D_004F7668[];
extern char D_004F7670[];
extern char D_00555070[];
extern int GObj_IdentityB(int);
extern int ObjMan_DeleteAll(cObjectiveMan*);
extern int ObjMan_SetDisplayLabel(cObjectiveMan*, int, int, int);
extern int ScriptFilter_Dispatch(int, int, int);
extern int* func_002257A0(void);
extern cObjectiveMan* ObjMan_ResolveReceiver(void*);
extern int* func_003CB1D0(void);
extern void func_003D9440(int, int);

/* Registers the cObjective script type with its parent type. */
void ScriptType_cObjective_Init(void) {
    int* parent = func_003CB1D0();
    func_003D9440(*(int*)D_004F7670, *parent);
}

/* Script value conversion; the volatile mirrors the original stack temporary. */
int func_00225770(int value) {
    volatile int tmp = value;
    return tmp;
}

void* Objective_ResolveReceiver(void* self) {
    return self;
}

/* Address of the cObjective script-type key. */
int* func_002257A0(void) {
    return (int*)D_004F7668;
}

int cObjective_v0B(void) {
    return *func_002257A0();
}

int Objective_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int Script_cObjectiveMan_DestroyObjectives(ScriptArg* args) {
    ObjMan_DeleteAll(ObjMan_ResolveReceiver(args[0].p));
    return 0;
}

/* SetDisplayLabel(label, gobj) */
int ObjMan_ScriptSetDisplayLabelObj(ScriptArg* args) {
    volatile int tmp = args[1].i;
    int label = tmp;
    ObjMan_SetDisplayLabel(ObjMan_ResolveReceiver(args[0].p), label, GObj_IdentityB(args[2].i), 0);
    return 0;
}

/* SetDisplayLabel(label) */
int ObjMan_ScriptSetDisplayLabel(ScriptArg* args) {
    volatile int label = args[1].i;
    ObjMan_SetDisplayLabel(ObjMan_ResolveReceiver(args[0].p), label, 0, 0);
    return 0;
}
