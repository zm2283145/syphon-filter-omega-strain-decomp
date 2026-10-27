/*
 * SFOGame/Source/human: 3 files, 00189FD0-0018A0A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00189FD0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "nested_null_dtor.h"
#pragma pop
#include "types.h"

#pragma cplusplus on

DEFINE_NESTED_NULL_DTOR3(func_00189FD0, func_001BE5A0)
static inline void merge_flush_func_00189FD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00189FD0 */

/* merge_units: begin func_0018A040 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void);
void operator_delete(void* p);

}
extern "C" void* cArray_FixedSize_cSkaAnimEvent_7_dtor(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array(self, (void*)func_0018A210, 8, 7);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A040 */

/* merge_units: begin func_0018A0A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void ActionFlags_Clear(int* pair) {
    pair[0] = 0;
    pair[1] = 0;
}
static inline void merge_flush_func_0018A0A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A0A0 */
