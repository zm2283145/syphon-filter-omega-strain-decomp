/*
 * SFOGame/Source/humanAnimData: 12 files, 001F23C0-001F2800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F23C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "member0_dtor.h"
DEFINE_MEMBER0_DTOR(cSkaTransBLEND_dtor, cArray_cSkaBlendSequenceItem_dtor)
static inline void merge_flush_func_001F23C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F23C0 */

/* merge_units: begin func_001F2420 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_MEMBER0_DTOR(cArray_cSkaBlendSequenceItem_dtor, std_vector_cSkaBlendSequenceItem_dtor)
static inline void merge_flush_func_001F2420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2420 */

/* merge_units: begin func_001F2480 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"
DEFINE_DIRECT_BASE_DTOR(std_vector_cSkaBlendSequenceItem_dtor, std_vector_imp_cSkaBlendSequenceItem_dtor)
static inline void merge_flush_func_001F2480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2480 */

/* merge_units: begin func_001F24E0 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_DIRECT_BASE_DTOR(std_vector_imp_cSkaBlendSequenceItem_dtor, std_vector_deleter_cSkaBlendSequenceItem_dtor)
static inline void merge_flush_func_001F24E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F24E0 */

/* merge_units: begin func_001F2540 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cSkaInitListOfPointers_cSkaSwitchItem_dtor, cLList_cSkaSwitchItemPtr_dtor)
#pragma optimization_level reset
static inline void merge_flush_func_001F2540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2540 */

/* merge_units: begin func_001F25B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cLList_cSkaSwitchItemPtr_dtor, std_list_cSkaSwitchItemPtr_dtor)
#pragma optimization_level reset
static inline void merge_flush_func_001F25B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F25B0 */

/* merge_units: begin func_001F2620 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor (built at -O1). */
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(std_list_cSkaSwitchItemPtr_dtor, func_00135C90)
#pragma optimization_level reset
static inline void merge_flush_func_001F2620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2620 */

/* merge_units: begin func_001F2690 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern int details_compressed_pair_imp_cAllocator_node_node_base_1_second_void(void*);

int std_list_deleter_voidPtr_tail(char* self) {
    return details_compressed_pair_imp_cAllocator_node_node_base_1_second_void(self + 4);
}

Word* std_list_deleter_voidPtr_generic_iterator_ctor_nodeP(Word* self, int value) {
    self->value = value;
    return self;
}
static inline void merge_flush_func_001F2690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2690 */

/* merge_units: begin func_001F26B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cSkaInitListOfPointers_cSkaTransBLEND_dtor, cLList_cSkaTransBLENDPtr_dtor)
#pragma optimization_level reset
static inline void merge_flush_func_001F26B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F26B0 */

/* merge_units: begin func_001F2720 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cLList_cSkaTransBLENDPtr_dtor, std_list_cSkaTransBLENDPtr_dtor)
#pragma optimization_level reset
static inline void merge_flush_func_001F2720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2720 */

/* merge_units: begin func_001F2790 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor (built at -O1). */
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(std_list_cSkaTransBLENDPtr_dtor, func_00135C90)
#pragma optimization_level reset
static inline void merge_flush_func_001F2790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2790 */

/* merge_units: begin func_001F2800 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
extern "C" void cArray_cSkaTransBLEND_dtor(void* m, int flags);
extern "C" void cPointer_cSkaNode_dtor(void* m, int flags);
extern "C" void* cSkaSwitchItem_dtor(void* self, short deleteFlag)
{
    if (self) {
        cArray_cSkaTransBLEND_dtor((char*)self + 4, -1);
        cPointer_cSkaNode_dtor(self, -1);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_001F2800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2800 */
