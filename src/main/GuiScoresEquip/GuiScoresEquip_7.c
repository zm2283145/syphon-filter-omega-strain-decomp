/*
 * main/GuiScoresEquip: 2 files, 0035FA40-0035FAC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035FA40 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } String;
extern int strlen(const char* s);
extern void String_Reserve(String* str, int n);
extern void String_Replace(String* str, int pos, int count, const char* first, const char* last, Alloc alloc);
/* Construct a string from a C string. */
String* String_CtorCStr_35FA40(String* str, const char* s)
{
    Alloc alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    String_Reserve(str, n);
    String_Replace(str, 0, 0, s, s + n, alloc);
    return str;
}
#pragma pop /* merge_units */
/* merge_units: end func_0035FA40 */

/* merge_units: begin func_0035FAC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BB700[] = "basic_string: out_of_range"; }
extern "C" { char D_004BB720[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_0035FAC0, D_004BB700, D_004BB720, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00492EB0, D_00492EB8, Libc_Memmove, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_0035FAC0 */
