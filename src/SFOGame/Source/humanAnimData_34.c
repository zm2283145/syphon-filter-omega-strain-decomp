/*
 * SFOGame/Source/humanAnimData: 2 files, 001F39C0-001F39F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F39C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void std_list_deleter_voidPtr_ctor_void(ScalarCollection*);

ScalarCollection* std_list_imp_voidPtr_ctor(ScalarCollection* self) {
    std_list_deleter_voidPtr_ctor_void(self);
    return self;
}
static inline void merge_flush_func_001F39C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F39C0 */

/* merge_units: begin func_001F39F0 */
#pragma push /* merge_units */
extern void cLList_cSkaSwitchItemPtr_ctor(void* p);
/* Calls cLList_cSkaSwitchItemPtr_ctor on the object and returns it. */
#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaSwitchItem_ctor(void* p) { cLList_cSkaSwitchItemPtr_ctor(p); return p; }
#pragma optimization_level reset
static inline void merge_flush_func_001F39F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F39F0 */
