/*
 * main/scriptManager: range (2 files, 003DC470-003DC4C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptManager_types.h"

/* merge_units: begin func_003DC470 */
#pragma push /* merge_units */
int* cArray_EnumDefPtr_opIndex(PtrVec* v, int i); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern PtrVec* D_00554F30;  /* global enum table (ScriptEnum* entries, ids start at 10) */
#if 0 /* merge_units */
extern ScriptEnum** cArray_EnumDefPtr_opIndex(PtrVec* v, int i);
#endif /* merge_units */
#define cArray_EnumDefPtr_opIndex(a0, a1) ((ScriptEnum * *)cArray_EnumDefPtr_opIndex((a0), (a1))) /* merge_units */

extern int cScriptInterpreter_SymbolTable_remapEnum(Script* script, int localId);

/* First word of member 'index' of the script-local enum 'localId'. */
int cScriptInterpreter_SymbolTable_remapEnumVal(Script* script, int localId, int index) {
    int id = cScriptInterpreter_SymbolTable_remapEnum(script, localId);
    ScriptEnum* e = *cArray_EnumDefPtr_opIndex(D_00554F30, id - 10);
    return e->members[index].unk0;
}
#undef cArray_EnumDefPtr_opIndex /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DC470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DC470 */

/* merge_units: begin func_003DC4C0 */
#pragma push /* merge_units */
int* cArray_EnumDefPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

/* Maps a script-local enum id (>= 10) to the global enum id. */
int cScriptInterpreter_SymbolTable_remapEnum(Script* script, int localId) {
    int i = localId - 10;

    return script->enumMap[i];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DC4C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DC4C0 */
