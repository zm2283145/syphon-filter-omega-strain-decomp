/*
 * main/GuiFrontendCanvas: 4 files, 00465FA0-00466840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00465FA0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "string_replace_range_xd.h"

extern "C" { char D_004C29B0[] = "basic_string: out_of_range"; }
extern "C" { char D_004C29D0[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE_XD(func_00465FA0, D_004C29B0, D_004C29D0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00497BF8, D_00497C00, func_00125FE8, String_Assign, String_Dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00465FA0 */

/* merge_units: begin func_00466410 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004C29F0[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(func_00466410, D_004C29F0, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00466410 */

/* merge_units: begin func_00466750 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_00466750)
#pragma pop /* merge_units */
/* merge_units: end func_00466750 */

/* merge_units: begin func_00466840 */
#pragma push /* merge_units */
/* Short/long string header: bit 0 = long form, bits 1-7 = inline length. */
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;

/* Empty allocator object passed by value (its byte is never initialized). */
typedef struct Alloc {
    char unused;
    char pad[3];
} Alloc;

extern void String_Replace(StrHdr* str, int start, int len, int a, int b, char alloc);

/* Forwards the whole string (start 0, current length) to String_Replace. */
void func_00466840(StrHdr* str, int a, int b) {
    volatile Alloc alloc;
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    String_Replace(str, 0, len, a, b, alloc.unused);
}
#pragma pop /* merge_units */
/* merge_units: end func_00466840 */
