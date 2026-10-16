/*
 * main/interface_model: 3 files, 003EEAC0-003EEB20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EEAC0 */
#pragma push /* merge_units */
#include "types.h"

extern void* String_AssignCStr_1C43A0(void* obj);

/* Returns whether String_AssignCStr_1C43A0 yields null. */
int func_003EEAC0(void* obj) {
    return String_AssignCStr_1C43A0(obj) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EEAC0 */

/* merge_units: begin func_003EEAF0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int String_AssignCStr_1C43A0(void* self);
#endif /* merge_units */
#define String_AssignCStr_1C43A0(a0) ((int)String_AssignCStr_1C43A0((a0))) /* merge_units */


/* Returns 1 if String_AssignCStr_1C43A0 returns 0. */
int func_003EEAF0(void* self)
{
    return String_AssignCStr_1C43A0(self) == 0;
}
#undef String_AssignCStr_1C43A0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EEAF0 */

/* merge_units: begin func_003EEB20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_003EEB20(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EEB20 */
