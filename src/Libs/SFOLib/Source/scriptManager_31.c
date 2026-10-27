/*
 * main/scriptManager: range (4 files, 003E1900-003E1A00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptManager_types.h"

/* merge_units: begin func_003E1900 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern ListPos* std_list_deleter_voidPtr_insert(ListPos* result, void* list, ListPos* pos, int value);
extern OwnedVec* std_vector_imp_SubScriptPtr_1_ctor(OwnedVec* v);

/* push_back on a list whose sentinel node is at +4. */
ListPos* std_list_SymbolTablePtr_push_back(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}

OwnedVec* cArray_SubScriptPtr_ctor(OwnedVec* v) {
    std_vector_imp_SubScriptPtr_1_ctor(v);
    v->unk0C = 1;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1900 */

/* merge_units: begin func_003E1960 */
#pragma push /* merge_units */
extern OwnedVec* std_vector_imp_FuncDefPtr_1_ctor(OwnedVec* v);

/* Clears the three PtrVec words. */
OwnedVec* std_vector_imp_SubScriptPtr_1_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

OwnedVec* cArray_FuncDefPtr_ctor(OwnedVec* v) {
    std_vector_imp_FuncDefPtr_1_ctor(v);
    v->unk0C = 1;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1960 */

/* merge_units: begin func_003E19B0 */
#pragma push /* merge_units */
extern OwnedVec* std_vector_imp_VarDefPtr_1_ctor(OwnedVec* v);

/* Clears the three PtrVec words. */
OwnedVec* std_vector_imp_FuncDefPtr_1_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

OwnedVec* cArray_VarDefPtr_ctor(OwnedVec* v) {
    std_vector_imp_VarDefPtr_1_ctor(v);
    v->unk0C = 1;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E19B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E19B0 */

/* merge_units: begin func_003E1A00 */
#pragma push /* merge_units */
/* Clears the three PtrVec words. */
OwnedVec* std_vector_imp_VarDefPtr_1_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1A00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1A00 */
