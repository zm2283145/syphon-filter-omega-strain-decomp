/*
 * main/scriptManager: range (6 files, 003E13B0-003E14E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptManager_types.h"

/* merge_units: begin func_003E13B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* cLListIterator_SymbolTablePtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_SymbolTablePtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_SymbolTablePtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E13B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E13B0 */

/* merge_units: begin func_003E13E0 */
#pragma push /* merge_units */
extern void* cScriptInterpreter_SOBJ_convert(int handle);
extern int ScriptMgr_ReloadScript(void* mgr, int name);
/* Script: cScriptInterpreter.ReloadScript(name). */
int Script_cScriptInterpreter_ReloadScript(int* args)
{
    volatile int result; /* both staged through the stack */
    volatile int name = args[1];
    result = ScriptMgr_ReloadScript(cScriptInterpreter_SOBJ_convert(args[0]), name);
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E13E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E13E0 */

/* merge_units: begin func_003E1420 */
#pragma push /* merge_units */
typedef struct LoadScriptArgs {
    int interp;
    int name;
    int flag;
} LoadScriptArgs;

#if 0 /* merge_units */
extern int cScriptInterpreter_SOBJ_convert(int handle);
#endif /* merge_units */
#define cScriptInterpreter_SOBJ_convert(a0) ((int)cScriptInterpreter_SOBJ_convert((a0))) /* merge_units */

extern int ScriptMgr_LoadScript(int interp, int name, int flag);

/* Script native: cScriptInterpreter.LoadScript(name, flag). */
int Script_cScriptInterpreter_LoadScript_2(LoadScriptArgs* args) {
    volatile int result;
    volatile int name;
    int flag = args->flag != 0;
    int interp;
    name = args->name;
    interp = cScriptInterpreter_SOBJ_convert(args->interp);
    result = ScriptMgr_LoadScript(interp, name, flag);
    return result;
}
#undef cScriptInterpreter_SOBJ_convert /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1420 */

/* merge_units: begin func_003E1470 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int ScriptMgr_LoadScript(void* mgr, int name, int flags);
#endif /* merge_units */
#define ScriptMgr_LoadScript(a0, a1, a2) (ScriptMgr_LoadScript((int)(a0), (a1), (a2))) /* merge_units */

/* Script: cScriptInterpreter.LoadScript(name). */
int Script_cScriptInterpreter_LoadScript(int* args)
{
    volatile int result; /* both staged through the stack */
    volatile int name = args[1];
    result = ScriptMgr_LoadScript(cScriptInterpreter_SOBJ_convert(args[0]), name, 0);
    return result;
}
#undef ScriptMgr_LoadScript /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1470 */

/* merge_units: begin func_003E14B0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* cScriptInterpreter_SOBJ_convert(void* p);
#endif /* merge_units */
#define cScriptInterpreter_SOBJ_convert(a0) (cScriptInterpreter_SOBJ_convert((int)(a0))) /* merge_units */

extern int cScriptInterpreter_CheckAllReferences(void* p);

/* Script native: checks all references of the interpreter's script. */
unsigned char Script_cScriptInterp_CheckAllReferences(void** self)
{
    return cScriptInterpreter_CheckAllReferences(cScriptInterpreter_SOBJ_convert(*self));
}
#undef cScriptInterpreter_SOBJ_convert /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E14B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E14B0 */

/* merge_units: begin func_003E14E0 */
#pragma push /* merge_units */
extern void cScriptInterpreter_ExecuteInitCode(void* interp);
#if 0 /* merge_units */
extern void* cScriptInterpreter_SOBJ_convert(void* self);
#endif /* merge_units */
#define cScriptInterpreter_SOBJ_convert(a0) (cScriptInterpreter_SOBJ_convert((int)(a0))) /* merge_units */


/* Script native: runs the init code of interpreter args[0]. */
int Script_cScriptInterp_ExecuteInitCode(ScriptArg* args) {
    cScriptInterpreter_ExecuteInitCode(cScriptInterpreter_SOBJ_convert(args[0].p));
    return 0;
}

void cScriptInterpreter_SOBJ_init(void) {
}
#undef cScriptInterpreter_SOBJ_convert /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E14E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E14E0 */
