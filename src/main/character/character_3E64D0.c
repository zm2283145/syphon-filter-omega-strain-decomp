/*
 * main/character: 4 files, 003E64D0-003E6650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E64D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script natives for the PerformAction family.
 */

#include "types.h"
#include "loose04_types.h"

extern int GObj_IdentityB(int handle);
extern int Global_PerformAction_WithObject(int obj, int action, int target, int arg, int flags, float time);
extern int Script_ValueToObj(int handle);
extern int ObjectAction_SendKind7(int obj, int action, int target, int arg, float time);

/* PerformAction_WithObject(obj, action, target, arg). */
int Script_PerformAction_WithObject_2(L4ScriptArg* args) {
    volatile int arg = args[3].i; /* reloaded from the stack in the original */
    int obj;
    int action;

    action = args[1].c;
    obj = Script_ValueToObj(args[0].i);
    Global_PerformAction_WithObject(obj, action, GObj_IdentityB(args[2].i), arg, 0, -1.0f);
    return 0;
}

/* PerformAction_WithObject(obj, action, target). */
int Script_PerformAction_WithObject(L4ScriptArg* args) {
    int obj;
    int action;

    action = args[1].c;
    obj = Script_ValueToObj(args[0].i);
    ObjectAction_SendKind7(obj, action, GObj_IdentityB(args[2].i), 0, -1.0f);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E64D0 */

/* merge_units: begin func_003E65A0 */
#pragma push /* merge_units */
#pragma opt_propagation off

typedef union ScriptArg { int i; float f; void* p; signed char c; } ScriptArg;
#if 0 /* merge_units */
extern void* Script_ValueToObj(void* object);
#endif /* merge_units */
#define Script_ValueToObj(a0) ((void *)Script_ValueToObj((int)(a0))) /* merge_units */

extern void Global_PerformAction_2(void* actor, signed char action, int target, int zero, float value);

/* Script native: makes the actor of args[0] perform action args[1] on args[2] with value args[3]; returns 0. */
int Script_PerformAction_3(ScriptArg* args)
{
    int value[1];
    int target[1];
    float v;
    value[0] = args[3].i;
    target[0] = args[2].i;
    v = *(float*)value;
    Global_PerformAction_2(Script_ValueToObj(args[0].p), args[1].c, *(int*)target, 0, v);
    return 0;
}
#undef Script_ValueToObj /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E65A0 */

/* merge_units: begin func_003E6600 */
#pragma push /* merge_units */
typedef struct ActionArgs3 {
    void* obj;
    signed char action;
    char pad5[3];
    int param;
} ActionArgs3;

#if 0 /* merge_units */
extern void* Script_ValueToObj(void* obj);
#endif /* merge_units */
#define Script_ValueToObj(a0) ((void *)Script_ValueToObj((int)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void Global_PerformAction_2(void* actor, int action, int param, int extra, float time);
#endif /* merge_units */
#define Global_PerformAction_2(a0, a1, a2, a3, a4) (Global_PerformAction_2((a0), (signed char)(a1), (a2), (a3), (a4))) /* merge_units */


/* Script native: PerformAction(obj, action, param). */
int Script_PerformAction_2(ActionArgs3* args) {
    volatile int paramSlot = args->param;
    Global_PerformAction_2(Script_ValueToObj(args->obj), args->action, paramSlot, 0, -1.0f);
    return 0;
}
#undef Script_ValueToObj /* merge_units */
#undef Global_PerformAction_2 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E6600 */

/* merge_units: begin func_003E6650 */
#pragma push /* merge_units */
typedef struct ActionArgs {
    void* obj;
    signed char action;
} ActionArgs;

#if 0 /* merge_units */
extern void* Script_ValueToObj(void* obj);
#endif /* merge_units */
#define Script_ValueToObj(a0) ((void *)Script_ValueToObj((int)(a0))) /* merge_units */

extern void Global_PerformAction(void* actor, int action);

/* Script native: PerformAction(obj, action). */
int Script_PerformAction(ActionArgs* args) {
    Global_PerformAction(Script_ValueToObj(args->obj), args->action);
    return 0;
}
#undef Script_ValueToObj /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E6650 */
