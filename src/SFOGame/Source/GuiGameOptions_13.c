/*
 * SFOGame/Source/GuiGameOptions: 4 files, 0029C120-0029C9C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029C120 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "string_replace_range_xd.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "string_reserve.h"
#pragma pop

#pragma cplusplus on

extern "C" {
char D_004AA9A0[] = "basic_string: out_of_range";
}
extern "C" {
char D_004AA9C0[] = "basic_string: length_error";
}
DEFINE_STRING_REPLACE_RANGE_XD(String_Replace_29C120, D_004AA9A0, D_004AA9C0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048B910, D_0048B918, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP, String_Dtor)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029C120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029C120 */

/* merge_units: begin func_0029C590 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004AA9E0[] = "basic_string::reserve length_error";
}
DEFINE_STRING_RESERVE(String_Reserve_29C590, D_004AA9E0, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029C590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029C590 */

/* merge_units: begin func_0029C8D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_0029C8D0)
static inline void merge_flush_func_0029C8D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029C8D0 */

/* merge_units: begin func_0029C9C0 */
#pragma push /* merge_units */
/* Short-string-optimized string: bit 0 of the first byte marks heap storage. */
typedef struct SsoString {
    union {
        struct { unsigned char isLong : 1; unsigned char shortLen : 7; } s;
        int flags;
    } h;
    int longLen;
    char* longData;
} SsoString;

typedef struct { char unused; } Allocator; /* empty allocator object passed by value */

/* Replaces count characters at pos with the range [first, last). */
extern void* std_basic_string_char_char_traits_char_do_replace(SsoString* str, int pos, int count, const char* first, const char* last, Allocator alloc);

/* Assigns the range [first, last) to the string (replaces the whole contents). */
void* func_0029C9C0(SsoString* str, const char* first, const char* last)
{
    Allocator alloc;
    int len;
    if (!(str->h.flags & 1))
        len = (unsigned char)str->h.s.shortLen;
    else
        len = str->longLen;
    return std_basic_string_char_char_traits_char_do_replace(str, 0, len, first, last, alloc);
}
static inline void merge_flush_func_0029C9C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029C9C0 */
