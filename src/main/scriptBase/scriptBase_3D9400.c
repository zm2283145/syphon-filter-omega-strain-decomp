/*
 * main/scriptBase: range (2 files, 003D9400-003D9440)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptBase_types.h"

/* merge_units: begin func_003D9400 */
#pragma push /* merge_units */
typedef struct { char pad[8]; char** types; } TypeTable003D9400;
extern TypeTable003D9400* D_00554F28;
extern void PtrVec_PushBack_1C1080(void* list, int* value);
/* Add an accepted interface to a script type. */
void ScriptType_AddAccepted(int type, int iface)
{
    int i = type - 100;
    PtrVec_PushBack_1C1080(D_00554F28->types[i] + 0x24, &iface);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D9400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D9400 */

/* merge_units: begin func_003D9440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern PtrVec* D_00554F28;  /* global script type table (ScriptType* entries, ids start at 100) */
#endif /* merge_units */
#define D_00554F28 (*(PtrVec **)&D_00554F28) /* merge_units */


/* Sets field +0x40 of script type 'typeId'. */
void ScriptType_SetParent(int typeId, int value) {
    int i = typeId - 100;
    ScriptType* type = (ScriptType*)D_00554F28->data[i];

    type->unk40 = value;
}
#undef D_00554F28 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D9440(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D9440 */
