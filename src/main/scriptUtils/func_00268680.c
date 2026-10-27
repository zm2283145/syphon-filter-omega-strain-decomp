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
