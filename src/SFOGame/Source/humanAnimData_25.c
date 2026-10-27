/*
 * SFOGame/Source/humanAnimData: 2 files, 001F3530-001F3540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3530 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char* std_list_deleter_voidPtr_generic_iterator_1_opMul(Iter16*);

char* std_list_cSkaTransBLENDPtr_generic_iterator_1_opMul(Iter16* it) {
    return std_list_deleter_voidPtr_generic_iterator_1_opMul(it);
}
static inline void merge_flush_func_001F3530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3530 */

/* merge_units: begin func_001F3540 */
#pragma push /* merge_units */
typedef struct { int value; } Temp;
extern void std_list_cSkaTransBLENDPtr_end(Temp* out);
extern void cConstLListIterator_cSkaTransBLENDPtr_ctor(void* self, Temp* in);

/* Builds a temporary with std_list_cSkaTransBLENDPtr_end and applies it to self. */
void cLList_cSkaTransBLENDPtr_End(void* self)
{
    Temp t;
    std_list_cSkaTransBLENDPtr_end(&t);
    cConstLListIterator_cSkaTransBLENDPtr_ctor(self, &t);
}
static inline void merge_flush_func_001F3540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3540 */
