/*
 * main/guiManager: 3 files, 0041B5F0-0041B990
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041B5F0 */
#pragma push /* merge_units */
#include "types.h"

/* Short-string-optimized string: bit 0 of the first word selects the long form. */
typedef union String {
    struct {
        unsigned int cap;
        int size;
        char* data;
    } l;
    struct {
        unsigned char isLong : 1;
        unsigned char size : 7;
        char data[11];
    } s;
} String;

/* Empty tag object passed by value (an allocator in the original C++). */
typedef struct Tag {
    signed char unused;
} Tag;

extern void std_basic_string_char_char_traits_char_do_replace(String*, int, int, char*, Tag*, Tag);

/* Appends one character to the string (insert at end). */
void String_PushBack_41B5F0(String* str, char c) {
    Tag tag;
    int size;
    if (str->l.cap & 1) {
        size = str->l.size;
    } else {
        size = (unsigned char)str->s.size;
    }
    std_basic_string_char_char_traits_char_do_replace(str, size, 0, &c, &tag, tag);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041B5F0 */

/* merge_units: begin func_0041B650 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004BF210[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(String_Reserve_41B650, D_004BF210, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0041B650 */

/* merge_units: begin func_0041B990 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_41B990)
#pragma pop /* merge_units */
/* merge_units: end func_0041B990 */
