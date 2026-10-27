/*
 * SFOGame/Source/humanAnimData: 5 files, 001F3C60-001F3DC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3C60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cAllocator_cSkaBlendSequenceItem_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_001F3C60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3C60 */

/* merge_units: begin func_001F3C70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor, cLList_cSkaBlendSequenceItemPtr_dtor)
#pragma optimization_level reset
static inline void merge_flush_func_001F3C70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3C70 */

/* merge_units: begin func_001F3CE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor (built at -O1). */
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cLList_cSkaBlendSequenceItemPtr_dtor, std_list_cSkaBlendSequenceItemPtr_dtor)
#pragma optimization_level reset
static inline void merge_flush_func_001F3CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3CE0 */

/* merge_units: begin func_001F3D50 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor (built at -O1). */
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(std_list_cSkaBlendSequenceItemPtr_dtor, func_00135C90)
#pragma optimization_level reset
static inline void merge_flush_func_001F3D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3D50 */

/* merge_units: begin func_001F3DC0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkaBlendSequenceExtents_dtor)
static inline void merge_flush_func_001F3DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3DC0 */
