/*
 * main/guiManager: 3 files, 0041AF30-0041AFE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041AF30 */
#pragma push /* merge_units */
#include "types.h"

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
extern unsigned int strlen(const char* s);
extern void String_Reserve(SsoString* str, unsigned int n);
extern void* String_Replace(SsoString* str, int pos, int count, const char* first, const char* last, Allocator alloc);

/* Constructs the string from a C string. */
SsoString* func_0041AF30(SsoString* str, const char* text)
{
    Allocator alloc;
    unsigned int len;
    str->h.flags = 0;
    str->longLen = 0;
    str->longData = 0;
    len = strlen(text);
    String_Reserve(str, len);
    String_Replace(str, 0, 0, text, text + len, alloc);
    return str;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041AF30 */

/* merge_units: begin func_0041AFB0 */
#pragma push /* merge_units */
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

extern void func_0013D710(String*, int, int, int);

/* Calls func_0013D710(str, size(str), 0, arg). */
void func_0041AFB0(String* str, int arg)
{
    int size;
    if (str->l.cap & 1)
        size = str->l.size;
    else
        size = (unsigned char)str->s.size;
    func_0013D710(str, size, 0, arg);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041AFB0 */

/* merge_units: begin func_0041AFE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BF1D0[] = "basic_string: out_of_range"; }
extern "C" { char D_004BF1F0[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_0041AFE0, D_004BF1D0, D_004BF1F0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00494100, D_00494108, func_00125FE8, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_0041AFE0 */
