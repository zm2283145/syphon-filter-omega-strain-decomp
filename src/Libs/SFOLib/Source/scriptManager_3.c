/*
 * Libs/SFOLib/Source/scriptManager: 3 files, 003D9C80-003D9D20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin group_3D9C80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int cScriptInterpreter_PackPtr(int obj);
#if 0 /* merge_units */
extern int cGroup_Find_cObjectIdR(void* self, int* id);
#endif /* merge_units */
int cGroup_Find_cObjectIdR(); /* merge_units */


/* Converts obj to its script id and passes it by address to cGroup_Find_cObjectIdR. */
void cGroup_Find_cSystemP(void* self, int obj) {
    int loc[1];

    loc[0] = cScriptInterpreter_PackPtr(obj);
    cGroup_Find_cObjectIdR(self, loc);
}
static inline void merge_flush_group_3D9C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end group_3D9C80 */

/* merge_units: begin group_3D9CC0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct Group{int cap,count;int*items;}Group;
int cGroup_Find_cObjectIdR(Group*g,int*value){int count=g->count;int i=0;if(0<count){int*items=g->items;int needle=*value;do{int current=items[i];if(current==needle)return i;i++;}while(i<count);}return -1;}
static inline void merge_flush_group_3D9CC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end group_3D9CC0 */

/* merge_units: begin func_003D9D20 */
#pragma push /* merge_units */
#include "scriptManager_types.h"

extern ScriptManager D_00555070;
extern int strlen(void* obj);
extern int cScriptVars_extend(ScriptBound* self, int binding);
extern int cScriptInterpreter_FindScriptObj(ScriptManager* manager, void* obj, int* key, int* out);

/* Address of slot i in a word table. */
int* cScriptVars_getExtVar(int** table, int i) {
    return *table + i;
}

/* Looks up obj's script binding in the script manager (D_00555070) and hands it to cScriptVars_extend. */
void cScriptVars_initScriptlet(ScriptBound* self, void* obj) {
    int binding;

    if (obj != 0 && strlen(obj) != 0) {
        binding = 0;
        cScriptInterpreter_FindScriptObj(&D_00555070, obj, &self->key, &binding);
        cScriptVars_extend(self, binding);
    }
}
static inline void merge_flush_func_003D9D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9D20 */
