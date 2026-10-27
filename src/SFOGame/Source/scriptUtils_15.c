/*
 * SFOGame/Source/scriptUtils: 1 file, 00268680
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00268680 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern int Global_RemoveArray(ScriptArray* array);
extern int ScriptArray_Create(int arg);
extern int Array_SOBJ_toInt(int value);
extern ScriptArray* Array_SOBJ_convert(void* obj);

Word* cLListIterator_ArrayPtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_ArrayPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_ArrayPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* cLListIterator_cNodeListPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cNodeListPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cNodeListPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Script native: RemoveArray(args[0]). */
int Script_RemoveArray(ScriptArg* args) {
    Global_RemoveArray(Array_SOBJ_convert(args[0].p));
    return 0;
}

/* Script native: CreateArray(args[0]). volatile mirrors the original stack temporary. */
int Script_CreateArray(ScriptArg* args) {
    volatile int arg = args[0].i;
    return Array_SOBJ_toInt(ScriptArray_Create(arg));
}
static inline void merge_flush_func_00268680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268680 */
