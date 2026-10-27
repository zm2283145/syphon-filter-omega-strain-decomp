/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void std_list_deleter_voidPtr_end_void_2(Word*, int);
extern Word* std_list_deleter_voidPtr_generic_iterator_1_ctor(Word*, Word*);
extern Word* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(Word*, int);

Word* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listR(Word* dst, Word* src) {
    std_list_deleter_voidPtr_generic_iterator_1_ctor(dst, src);
    return dst;
}

void std_list_cSkaBlendSequenceItemPtr_end(Word* self, int a1) {
    Word tmp;

    std_list_deleter_voidPtr_end_void_2(&tmp, a1);
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}

Word* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(Word* dst, int value) {
    Word tmp;

    tmp.value = value;
    std_list_deleter_voidPtr_generic_iterator_1_ctor(dst, &tmp);
    return dst;
}
