/*
 * SFOGame/Source/humanAnimData: 2 files, 001F2E10-001F2E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F2E10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char* std_list_deleter_voidPtr_generic_iterator_1_opMul(Iter16*);

char* std_list_cSkaSwitchItemPtr_generic_iterator_1_opMul(Iter16* it) {
    return std_list_deleter_voidPtr_generic_iterator_1_opMul(it);
}

/* Address 8 bytes past the pointed-to node. */
char* std_list_deleter_voidPtr_generic_iterator_1_opMul(Iter16* it) {
    return it->p + 8;
}
static inline void merge_flush_func_001F2E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2E10 */

/* merge_units: begin func_001F2E30 */
#pragma push /* merge_units */
extern void std_list_cSkaSwitchItemPtr_end(int* out);
extern void cConstLListIterator_cSkaSwitchItemPtr_ctor(void* self, int* value);

/* Fetches a value with std_list_cSkaSwitchItemPtr_end and passes it to cConstLListIterator_cSkaSwitchItemPtr_ctor. */
void cLList_cSkaSwitchItemPtr_End(void* self)
{
    int value;
    std_list_cSkaSwitchItemPtr_end(&value);
    cConstLListIterator_cSkaSwitchItemPtr_ctor(self, &value);
}
static inline void merge_flush_func_001F2E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2E30 */
