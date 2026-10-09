/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern int D_004F8400;  /* cNodeList script type id (>= 100) */
extern void Group_AddObject(ScriptGroup* group, void* obj);
extern int Group_RemoveObject(ScriptGroup* group, void* obj);
extern void* func_0015C120(int handle);
extern int func_002697E0(int value);
extern cNodeList* func_00269810(void* obj);
extern int* func_003CB1D0(void);
extern void ScriptType_SetParent(int typeId, int value);
extern float func_003D9A00(ScriptGroup* group);
extern int func_003D9BA0(ScriptGroup* group, void* obj);

/* Script native: cNodeList.Randomize(). */
int Script_cNodeList_Randomize(ScriptArg* args) {
    func_003D9A00(func_00269810(args[0].p)->group);
    return 0;
}

/* Script native: cNodeList.Remove(obj handle = args[1]). */
int Script_cNodeList_Remove(ScriptArg* args) {
    void* obj = func_0015C120(args[1].i);
    Group_RemoveObject(func_00269810(args[0].p)->group, obj);
    return 0;
}

/* Script native: cNodeList.AddDup(obj handle = args[1]). */
int Script_cNodeList_AddDup(ScriptArg* args) {
    void* obj = func_0015C120(args[1].i);
    func_003D9BA0(func_00269810(args[0].p)->group, obj);
    return 0;
}

/* Script native: cNodeList.Add(obj handle = args[1]). */
int Script_cNodeList_Add(ScriptArg* args) {
    void* obj = func_0015C120(args[1].i);
    Group_AddObject(func_00269810(args[0].p)->group, obj);
    return 0;
}

/* Registers the cNodeList script type with the value returned by func_003CB1D0. */
void ScriptType_cNodeList_Init(void) {
    int* key = func_003CB1D0();
    ScriptType_SetParent(D_004F8400, *key);
}

int func_002697D0(int value) {
    return func_002697E0(value);
}

/* Identity. volatile mirrors the original stack temporary. */
int func_002697E0(int value) {
    volatile int v = value;
    return v;
}

cNodeList* func_00269800(void* obj) {
    return func_00269810(obj);
}
