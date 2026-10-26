/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void List_End_13D890(Word*, int);
extern Word* std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(Word*, int);

Word* std_list_deleter_voidPtr_generic_iterator_1_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSkaSwitchItemPtr_end(Word* self, int a1) {
    Word tmp;

    List_End_13D890(&tmp, a1);
    std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}
