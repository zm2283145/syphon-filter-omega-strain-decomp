/*
 * main/guiTextArrayWidget: 4 files, 00427000-00427180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00427000 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* std_vector_cArray_tTextElementPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00427000 */

/* merge_units: begin func_00427020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "owned_buffer8_dtor.h"

/* Free the owned buffer, optionally delete. */
DEFINE_OWNED_BUFFER8_DTOR(func_00427020, D_0049AF00)
#pragma pop /* merge_units */
/* merge_units: end func_00427020 */

/* merge_units: begin func_00427100 */
#pragma push /* merge_units */
typedef struct String {
    int a, b, c;
} String;

/* Empty tag object passed by value (an allocator in the original C++). */
typedef struct Tag {
    signed char unused;
} Tag;

extern int strlen(const char*);
extern void std_basic_string_char_char_traits_char_reserve(String*, int);
extern void std_basic_string_char_char_traits_char_do_replace(String*, int, int, const char*, const char*, Tag);

/* Constructs a string from a C string. */
String* String_CtorCStr_427100(String* self, const char* text) {
    Tag tag;
    int len;
    self->a = 0;
    self->b = 0;
    self->c = 0;
    len = strlen(text);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, text, text + len, tag);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00427100 */

/* merge_units: begin func_00427180 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BF7C0[] = "basic_string: out_of_range"; }
extern "C" { char D_004BF7E0[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_00427180, D_004BF7C0, D_004BF7E0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00494160, D_00494168, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP)
#pragma pop /* merge_units */
/* merge_units: end func_00427180 */
