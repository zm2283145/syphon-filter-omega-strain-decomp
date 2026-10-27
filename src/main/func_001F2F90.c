/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void std_list_deleter_voidPtr_begin_void_2(Word*, int);
extern Word* std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(Word*, int);
extern void std_vector_cSkaSwitchItem_clear(void);
extern void std_vector_imp_cSkaSwitchItem_clear(void);

void std_list_cSkaSwitchItemPtr_begin(Word* self, int a1) {
    Word tmp;

    std_list_deleter_voidPtr_begin_void_2(&tmp, a1);
    std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}

void cArray_cSkaSwitchItem_Clear(void) {
    std_vector_cSkaSwitchItem_clear();
}

void std_vector_cSkaSwitchItem_clear(void) {
    std_vector_imp_cSkaSwitchItem_clear();
}
