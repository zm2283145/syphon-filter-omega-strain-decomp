/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern int D_00506278;   /* cTank class type id */
extern int D_00506280;   /* cTank script type */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* Registers the cTank script type under its parent type. */
void ScriptType_cTank_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_00506280, *parent);
}

/* Identity casts; volatile mirrors the original stack temporary. */
int func_00283770(int obj) {
    volatile int tmp = obj;
    return tmp;
}

int func_00283790(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* func_002837B0(void* self) {
    return self;
}

void* func_002837C0(void* self) {
    return self;
}

int* func_002837D0(void) {
    return &D_00506278;
}

int* func_002837E0(void) {
    return &D_00506278;
}

int cTank_v0B(void) {
    return D_00506278;
}

int cTank_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
