/*
 * SFOGame/Source/humanAnimData: 2 files, 00207200-00207210
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00207200 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

#if 0 /* merge_units */
extern int std_basic_string_char_char_traits_char_size(int);
#endif /* merge_units */
int std_basic_string_char_char_traits_char_size(); /* merge_units */


int std_basic_string_char_char_traits_char_length(int a0) {
    return std_basic_string_char_char_traits_char_size(a0);
}
static inline void merge_flush_func_00207200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207200 */

/* merge_units: begin func_00207210 */
#pragma push /* merge_units */
extern int std_basic_string_char_char_traits_char_is_long(void* obj);
extern int* std_basic_string_char_char_traits_char_long_size(void* obj);
extern unsigned char std_basic_string_char_char_traits_char_short_size(void* obj);
/* Return the stored value if present, else a default byte value. */
int std_basic_string_char_char_traits_char_size(void* obj)
{
    if (std_basic_string_char_char_traits_char_is_long(obj)) {
        return *std_basic_string_char_char_traits_char_long_size(obj);
    }
    return std_basic_string_char_char_traits_char_short_size(obj);
}
static inline void merge_flush_func_00207210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207210 */
