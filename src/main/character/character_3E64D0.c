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

extern int cGOBJ_SOBJ_convert(int handle);
extern int nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_charP_etc(int obj, int action, int target, int arg, int flags, float time);
extern int cSystem_SOBJ_convert(int handle);
extern int nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(int obj, int action, int target, int arg, float time);

/* PerformAction_WithObject(obj, action, target, arg). */
int Script_PerformAction_WithObject_2(L4ScriptArg* args) {
    volatile int arg = args[3].i; /* reloaded from the stack in the original */
    int obj;
    int action;

    action = args[1].c;
    obj = cSystem_SOBJ_convert(args[0].i);
    nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_charP_etc(obj, action, cGOBJ_SOBJ_convert(args[2].i), arg, 0, -1.0f);
    return 0;
}

/* PerformAction_WithObject(obj, action, target). */
int Script_PerformAction_WithObject(L4ScriptArg* args) {
    int obj;
    int action;

    action = args[1].c;
    obj = cSystem_SOBJ_convert(args[0].i);
    nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(obj, action, cGOBJ_SOBJ_convert(args[2].i), 0, -1.0f);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E64D0 */

/* merge_units: begin func_003E65A0 */
#pragma push /* merge_units */
#pragma opt_propagation off

typedef union ScriptArg { int i; float f; void* p; signed char c; } ScriptArg;
#if 0 /* merge_units */
extern void* cSystem_SOBJ_convert(void* object);
#endif /* merge_units */
#define cSystem_SOBJ_convert(a0) ((void *)cSystem_SOBJ_convert((int)(a0))) /* merge_units */

extern void nCAS_PerformAction_cSystemP_eAction_charP_float_etc(void* actor, signed char action, int target, int zero, float value);

/* Script native: makes the actor of args[0] perform action args[1] on args[2] with value args[3]; returns 0. */
int Script_PerformAction_3(ScriptArg* args)
{
    int value[1];
    int target[1];
    float v;
    value[0] = args[3].i;
    target[0] = args[2].i;
    v = *(float*)value;
    nCAS_PerformAction_cSystemP_eAction_charP_float_etc(cSystem_SOBJ_convert(args[0].p), args[1].c, *(int*)target, 0, v);
    return 0;
}
#undef cSystem_SOBJ_convert /* merge_units */
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
extern void* cSystem_SOBJ_convert(void* obj);
#endif /* merge_units */
#define cSystem_SOBJ_convert(a0) ((void *)cSystem_SOBJ_convert((int)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void nCAS_PerformAction_cSystemP_eAction_charP_float_etc(void* actor, int action, int param, int extra, float time);
#endif /* merge_units */
#define nCAS_PerformAction_cSystemP_eAction_charP_float_etc(a0, a1, a2, a3, a4) (nCAS_PerformAction_cSystemP_eAction_charP_float_etc((a0), (signed char)(a1), (a2), (a3), (a4))) /* merge_units */


/* Script native: PerformAction(obj, action, param). */
int Script_PerformAction_2(ActionArgs3* args) {
    volatile int paramSlot = args->param;
    nCAS_PerformAction_cSystemP_eAction_charP_float_etc(cSystem_SOBJ_convert(args->obj), args->action, paramSlot, 0, -1.0f);
    return 0;
}
#undef cSystem_SOBJ_convert /* merge_units */
#undef nCAS_PerformAction_cSystemP_eAction_charP_float_etc /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E6600 */

/* merge_units: begin func_003E6650 */
#pragma push /* merge_units */
typedef struct ActionArgs {
    void* obj;
    signed char action;
} ActionArgs;

#if 0 /* merge_units */
extern void* cSystem_SOBJ_convert(void* obj);
#endif /* merge_units */
#define cSystem_SOBJ_convert(a0) ((void *)cSystem_SOBJ_convert((int)(a0))) /* merge_units */

extern void nCAS_PerformAction_cSystemP_eAction(void* actor, int action);

/* Script native: PerformAction(obj, action). */
int Script_PerformAction(ActionArgs* args) {
    nCAS_PerformAction_cSystemP_eAction(cSystem_SOBJ_convert(args->obj), args->action);
    return 0;
}
#undef cSystem_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E6650 */
