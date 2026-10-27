/*
 * SFOGame/Source/humanAnimData: 2 files, 001F3010-001F3030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3010 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

#if 0 /* merge_units */
extern int std_list_imp_voidPtr_size(void);
#endif /* merge_units */
int std_list_imp_voidPtr_size(); /* merge_units */

extern int std_vector_imp_cSkaSwitchItem_reserve(int, int);

int std_vector_cSkaSwitchItem_reserve(int a0, int a1) {
    return std_vector_imp_cSkaSwitchItem_reserve(a0, a1);
}

int cLList_cSkaSwitchItemPtr_Size(void) {
    return std_list_imp_voidPtr_size();
}
static inline void merge_flush_func_001F3010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3010 */

/* merge_units: begin func_001F3030 */
#pragma push /* merge_units */
extern int* std_list_deleter_voidPtr_sz_void_2(void* obj);

/* Returns the int pointed to by std_list_deleter_voidPtr_sz_void_2's result. */
int std_list_imp_voidPtr_size(void* obj) {
    return *std_list_deleter_voidPtr_sz_void_2(obj);
}
static inline void merge_flush_func_001F3030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3030 */
