/*
 * main/guiTextWidget: 2 files, 0041C870-0041C8F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041C870 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char unused; } Alloc;
typedef struct { int w0; int w1; int w2; } String;
extern int strlen(const char* s);
extern void std_basic_string_char_char_traits_char_reserve(String* str, int capacity);
extern void std_basic_string_char_char_traits_char_do_replace(String* str, int pos, int n, const char* first, const char* last, Alloc alloc);

/* String constructor from a C string. */
String* String_CtorCStr_41C870(String* self, const char* cstr)
{
    Alloc alloc;
    int len;
    self->w0 = 0;
    self->w1 = 0;
    self->w2 = 0;
    len = strlen(cstr);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, cstr, cstr + len, alloc);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041C870 */

/* merge_units: begin func_0041C8F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BF2F0[] = "basic_string: out_of_range"; }
extern "C" { char D_004BF310[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_0041C8F0, D_004BF2F0, D_004BF310, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00494110, D_00494118, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP)
#pragma pop /* merge_units */
/* merge_units: end func_0041C8F0 */
