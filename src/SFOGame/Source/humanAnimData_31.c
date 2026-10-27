/*
 * SFOGame/Source/humanAnimData: 5 files, 001F3870-001F3900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3870 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cAllocator_cSkaTransBLEND_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_001F3870(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3870 */

/* merge_units: begin func_001F3880 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cLList_cSkaTransBLENDPtr_PushBackActual(void* s, int* v);
#endif /* merge_units */
void cLList_cSkaTransBLENDPtr_PushBackActual(); /* merge_units */

#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaTransBLEND_opShl(void* s, int v) { cLList_cSkaTransBLENDPtr_PushBackActual(s, &v); return s; }
#pragma optimization_level reset
static inline void merge_flush_func_001F3880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3880 */

/* merge_units: begin func_001F38C0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaTransBLENDPtr_push_back(void);
#endif /* merge_units */
void std_list_cSkaTransBLENDPtr_push_back(); /* merge_units */

/* Wrapper around std_list_cSkaTransBLENDPtr_push_back. */
#pragma optimization_level 1
void cLList_cSkaTransBLENDPtr_PushBackActual(void) { std_list_cSkaTransBLENDPtr_push_back(); }
#pragma optimization_level reset
static inline void merge_flush_func_001F38C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F38C0 */

/* merge_units: begin func_001F38E0 */
#pragma push /* merge_units */
/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void std_list_imp_voidPtr_push_back(void* self);

/* Forwards to std_list_imp_voidPtr_push_back. */
void std_list_cSkaTransBLENDPtr_push_back(void* self)
{
    std_list_imp_voidPtr_push_back(self);
}
static inline void merge_flush_func_001F38E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F38E0 */

/* merge_units: begin func_001F3900 */
#pragma push /* merge_units */
extern void cLList_cSkaTransBLENDPtr_ctor(void* s);
#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaTransBLEND_ctor(void* s) { cLList_cSkaTransBLENDPtr_ctor(s); return s; }
#pragma optimization_level reset
static inline void merge_flush_func_001F3900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3900 */
