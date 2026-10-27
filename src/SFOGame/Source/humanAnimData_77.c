/*
 * SFOGame/Source/humanAnimData: 3 files, 00207260-002072B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00207260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char* details_compressed_pair_imp_rep_s_2_first_void(void*);

char* std_basic_string_char_char_traits_char_long_size(void* self) {
    return details_compressed_pair_imp_rep_s_2_first_void(self) + 4;
}
static inline void merge_flush_func_00207260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207260 */

/* merge_units: begin func_00207280 */
#pragma push /* merge_units */
typedef union SsoHeader {
    unsigned char raw;
    struct { unsigned char isLong : 1; unsigned char len : 7; } bits;
} SsoHeader;

#if 0 /* merge_units */
extern SsoHeader* details_compressed_pair_imp_rep_s_2_first_void(void* self);
#endif /* merge_units */
#define details_compressed_pair_imp_rep_s_2_first_void(a0) ((SsoHeader *)details_compressed_pair_imp_rep_s_2_first_void((a0))) /* merge_units */


/* Returns the short-string length stored in the SSO header byte. */
unsigned char std_basic_string_char_char_traits_char_short_size(void* self)
{
    return details_compressed_pair_imp_rep_s_2_first_void(self)->bits.len;
}
#undef details_compressed_pair_imp_rep_s_2_first_void /* merge_units */
static inline void merge_flush_func_00207280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207280 */

/* merge_units: begin func_002072B0 */
#pragma push /* merge_units */
typedef struct { int words[4]; } Value16;
extern void cString_ctor_cStringR(Value16* dst, void* src);
extern void std_basic_string_char_char_traits_char_append_basicstringR(Value16* v, void* arg);
extern void String_Dtor_138350(Value16* v, int flags);

/* Builds a temporary from src, applies arg to it, copies it into dst, then destroys it; returns 0. */
int opAdd_cStringR_cStringR(void* dst, void* src, void* arg)
{
    Value16 tmp;
    cString_ctor_cStringR(&tmp, src);
    std_basic_string_char_char_traits_char_append_basicstringR(&tmp, arg);
    cString_ctor_cStringR(dst, &tmp);
    String_Dtor_138350(&tmp, -1);
    return 0;
}
static inline void merge_flush_func_002072B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002072B0 */
