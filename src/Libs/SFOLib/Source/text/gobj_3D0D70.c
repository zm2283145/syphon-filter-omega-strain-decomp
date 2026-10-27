/*
 * main/gobj: 2 files, 003D0D70-003D0DE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D0D70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int cTextSystem_Print_charP_cFontR_tRGBAR_float_etc(void* self, int a1, int first, int a2, float f0, float f1);

void std_list_cTextAreaPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cTextAreaPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cTextAreaPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* std_list_deleter_cText_generic_iterator_ctor_nodebaseP(Word* self, int value) {
    self->value = value;
    return self;
}

Word* std_list_deleter_cText_generic_iterator_ctor_nodeP(Word* self, int value) {
    self->value = value;
    return self;
}

void* std_list_deleter_cText_tail(char* self) {
    return self + 4;
}

/* Forwards to cTextSystem_Print_charP_cFontR_tRGBAR_float_etc with the object's first word inserted as the third argument. */
int cTextSystem_Print_charP_tRGBAR_float_float(Word* self, int a1, int a2, float f0, float f1) {
    return cTextSystem_Print_charP_cFontR_tRGBAR_float_etc(self, a1, self->value, a2, f0, f1);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D0D70 */

/* merge_units: begin func_003D0DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cText_dtor, String_Dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003D0DE0 */
