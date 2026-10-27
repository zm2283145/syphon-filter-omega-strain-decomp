/*
 * SFOGame/Source/humanAnimData: 2 files, 001F4170-001F4180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F4170 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char* std_list_deleter_voidPtr_generic_iterator_1_opMul(Iter16*);

char* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opMul(Iter16* it) {
    return std_list_deleter_voidPtr_generic_iterator_1_opMul(it);
}
static inline void merge_flush_func_001F4170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4170 */

/* merge_units: begin func_001F4180 */
#pragma push /* merge_units */
extern void std_list_cSkaBlendSequenceItemPtr_end(int*);
extern void cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(void*, int*);

/* Fetches a value via std_list_cSkaBlendSequenceItemPtr_end and passes it to cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(self, &value). */
void cLList_cSkaBlendSequenceItemPtr_End(void* self) {
    int value;
    std_list_cSkaBlendSequenceItemPtr_end(&value);
    cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(self, &value);
}
static inline void merge_flush_func_001F4180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4180 */
