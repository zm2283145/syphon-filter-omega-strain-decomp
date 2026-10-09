/*
 * Matched functions (byte-identical with the retail executable).
 * cNode script type registration and small helpers.
 */

#include "types.h"
#include "node_types.h"

extern int D_004EA778; /* cNode script type key */
extern int D_004EA780; /* cNode script type id */
extern char D_00555070[]; /* global script filter */
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cGOBJ_GetScriptTypeKeyPtr(void); /* address of the cGObj type key */
extern void ScriptType_SetParent(int type, int parentType);

void func_0015C080(void) {
}

int func_0015C090(void) {
    return 1;
}

int func_0015C0A0(void) {
    return 0;
}

/* IsType(object, mask): nonzero when the object's type bits intersect mask. */
int Script_cNode_IsType(NodeScriptArg* args) {
    NodeScriptObj* obj = args[0].p;
    return (unsigned int)(args[1].u16 & obj->typeMask) > 0u;
}

/* cNode derives from cGObj. */
void ScriptType_cNode_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004EA780, *parent);
}

/* volatile mirrors the original stack temporary. */
int func_0015C100(int value) {
    volatile int tmp = value;
    return tmp;
}

void* func_0015C120(void* self) {
    return self;
}

int* func_0015C130(void) {
    return &D_004EA778;
}

int cNode_v0B(void) {
    return D_004EA778;
}

int cNode_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
