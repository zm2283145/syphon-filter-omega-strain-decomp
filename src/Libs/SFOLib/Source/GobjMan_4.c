/*
 * Libs/SFOLib/Source/GobjMan: 2 files, 0040B410-0040B4B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin materialProperties_40B410 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "string_int_pair_copy_ctor.h"

/* Copy constructor of a string/int pair. */
DEFINE_STRING_INT_PAIR_COPY_CTOR(std_pair_cString_int_ctor)
static inline void merge_flush_materialProperties_40B410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end materialProperties_40B410 */

/* merge_units: begin func_0040B4B0 */
#pragma push /* merge_units */
typedef struct { int pad; int count; void** data; } Vec40B4B0;
extern Vec40B4B0* GetPurgeList(void);
extern void cBaseObjList_Purge(void* p);
#pragma push
#pragma opt_strength_reduction off
void cBaseObjList_PurgeRemovals(void)
{
    Vec40B4B0* v = GetPurgeList();
    int i;
    for (i = v->count - 1; i >= 0; i--) cBaseObjList_Purge(v->data[i]);
}
#pragma pop
static inline void merge_flush_func_0040B4B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B4B0 */
