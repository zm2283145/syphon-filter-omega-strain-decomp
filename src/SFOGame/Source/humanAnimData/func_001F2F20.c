/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* std_list_deleter_voidPtr_generic_iterator_1_ctor(Word*, Word*);

Word* std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(Word* dst, int value) {
    Word tmp;

    tmp.value = value;
    std_list_deleter_voidPtr_generic_iterator_1_ctor(dst, &tmp);
    return dst;
}
