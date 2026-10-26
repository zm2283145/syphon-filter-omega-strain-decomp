/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void List_Begin_16E880(Word*, int);
extern Word* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(Word*, int);
extern void std_vector_cSkaBlendSequenceItem_clear(void);
extern void std_vector_imp_cSkaBlendSequenceItem_clear(void);

void std_list_cSkaBlendSequenceItemPtr_begin(Word* self, int a1) {
    Word tmp;

    List_Begin_16E880(&tmp, a1);
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}

void cArray_cSkaBlendSequenceItem_Clear(void) {
    std_vector_cSkaBlendSequenceItem_clear();
}

void std_vector_cSkaBlendSequenceItem_clear(void) {
    std_vector_imp_cSkaBlendSequenceItem_clear();
}
