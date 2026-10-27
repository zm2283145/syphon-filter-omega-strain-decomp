/*
 * main/fireObj: range (4 files, 00261D10-00261D90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "fireObj_types.h"

/* merge_units: begin func_00261D10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cFireObj on/off virtuals.
 */


void cFireObj_NetEnable(cFireObj* self) {
    self->lit = 1;
}

void cFireObj_NetDisable(cFireObj* self) {
    self->lit = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261D10 */

/* merge_units: begin func_00261D30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cFireObj_00261D30 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int value); /* +0x68 */
};

/* Script native: cFireObj::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cFireObj_Disable(ScriptArg* args)
{
    cFireObj_00261D30* obj = (cFireObj_00261D30*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261D30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261D30 */

/* merge_units: begin func_00261D60 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00261D60 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00261D60;

/* Virtual-call view of cFireObj: only the slots used here are named (vtable offset in comments). */
struct cFireObj_00261D60 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cFireObj::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cFireObj_Enable(ScriptArg_00261D60* args)
{
    cFireObj_00261D60* obj = (cFireObj_00261D60*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261D60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261D60 */

/* merge_units: begin func_00261D90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cFireObj script type registration and class helpers.
 */


extern int D_004F8310;   /* cFireObj class type id */
extern int D_004F8318;   /* cFireObj script type */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int* cGOBJ_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int parentType);

/* Registers the cFireObj script type under its parent type. */
void cFireObj_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();

    cScriptBase_declareParent(D_004F8318, *parent);
}

int cFireObj_getSOBJClassId(void) {
    return D_004F8310;
}

int cFireObj_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261D90 */
