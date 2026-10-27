/*
 * SFOGame/Source/humanAnimData: 4 files, 002071A0-00207200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002071A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_basic_string_char_char_traits_char_c_str(int);

int cString_opCast_constcharPtr(int a0) {
    return std_basic_string_char_char_traits_char_c_str(a0);
}

void* details_compressed_pair_imp_rep_s_2_first_void(void* self) {
    return self;
}
static inline void merge_flush_func_002071A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002071A0 */

/* merge_units: begin func_002071C0 */
#pragma push /* merge_units */
#include "loose01_types.h"

#if 0 /* merge_units */
extern Word* details_compressed_pair_imp_rep_s_2_first_void(Word*);
#endif /* merge_units */
#define details_compressed_pair_imp_rep_s_2_first_void(a0) ((Word *)details_compressed_pair_imp_rep_s_2_first_void((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_length(void);
#endif /* merge_units */
int std_basic_string_char_char_traits_char_length(); /* merge_units */


/* Tests bit 0 of the word. */
int std_basic_string_char_char_traits_char_is_long(Word* self) {
    return (details_compressed_pair_imp_rep_s_2_first_void(self)->value & 1) != 0;
}

void cString_Length(void) {
    std_basic_string_char_char_traits_char_length();
}
#undef details_compressed_pair_imp_rep_s_2_first_void /* merge_units */
static inline void merge_flush_func_002071C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002071C0 */

/* merge_units: begin func_00207200 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
extern int std_basic_string_char_char_traits_char_is_long(void* obj);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_is_long(a0) (std_basic_string_char_char_traits_char_is_long((Word *)(a0))) /* merge_units */

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
#undef std_basic_string_char_char_traits_char_is_long /* merge_units */
static inline void merge_flush_func_00207210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207210 */
