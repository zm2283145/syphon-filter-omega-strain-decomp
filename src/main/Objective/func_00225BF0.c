/*
 * Matched functions (byte-identical with the retail executable).
 * cObjectiveMan script-type registration and the manager service lookup.
 */

#include "types.h"
#include "Objective_types.h"

extern char D_004F7578[];
extern char D_004F75E8[];
extern char D_004F75F0[];
extern char D_004FFB50[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern cObjectiveMan* Service_Lookup(int, int);
extern cObjectiveMan* func_00225C20(cObjectiveMan*);
extern int* func_00225C50(void);
extern cObjectiveMan* ObjMan_GetService(void);
extern int* func_003CB1D0(void);
extern void func_003D9440(int, int);

/* Registers the cObjectiveMan script type with its parent type. */
void ScriptType_cObjectiveMan_Init(void) {
    int* parent = func_003CB1D0();
    func_003D9440(*(int*)D_004F75F0, *parent);
}

/* Script value conversion; the volatile mirrors the original stack temporary. */
cObjectiveMan* func_00225C20(cObjectiveMan* value) {
    cObjectiveMan* volatile tmp = value;
    return tmp;
}

/* Receiver resolve for cObjectiveMan natives (identity). */
void* ObjMan_ResolveReceiver(void* self) {
    return self;
}

/* Address of the cObjectiveMan script-type key. */
int* func_00225C50(void) {
    return (int*)D_004F75E8;
}

int cObjectiveMan_v0B(void) {
    return *func_00225C50();
}

int cObjectiveMan_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

cObjectiveMan* Script_GetObjectiveManager(void) {
    return func_00225C20(ObjMan_GetService());
}

/* Looks up the objective manager in the global service registry. */
cObjectiveMan* ObjMan_GetService(void) {
    return Service_Lookup((int)D_004FFB50, (int)D_004F7578);
}
