/*
 * Libs/SFOLib/Source/scriptManager: 2 files, 003E1090-003E10D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E1090 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_FuncDefPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_FuncDefPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_FuncDefPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003E1090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E1090 */

/* merge_units: begin func_003E10D0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_strength_reduction off
typedef struct { int id; } VInfo3E10D0;
typedef struct { char* name; VInfo3E10D0* info; } Var3E10D0;
typedef struct { int x0; int count; Var3E10D0** items; } Tbl3E10D0;

extern Tbl3E10D0* D_00554F18;
extern char D_004BD858[];
extern int sprintf(char*, const char*, ...);
extern int String_CompareNoCase(char*, char*);

Var3E10D0* cScriptInterpreter_findVar(void* self, char* name, int id)
{
    char buf[128];
    int i;
    Var3E10D0* v;
    int n;
    n = D_00554F18->count;
    sprintf(buf, D_004BD858, name);
    for (i = 0; i < n; i++) {
        v = D_00554F18->items[i];
        if (id < 0 || id == v->info->id) {
            if (!String_CompareNoCase(v->name, name) || !String_CompareNoCase(v->name, buf)) {
                return v;
            }
        }
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_003E10D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E10D0 */
