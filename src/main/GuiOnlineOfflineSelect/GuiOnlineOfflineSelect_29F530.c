/*
 * main/GuiOnlineOfflineSelect: 3 files, 0029F530-0029F5E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029F530 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc0029F530; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } Str0029F530;
extern int strlen(const char* s);
extern void String_Reserve(Str0029F530* str, int n);
extern void String_Replace(Str0029F530* str, int pos, int count, const char* first, const char* last, Alloc0029F530 alloc);
/* Construct a string from a C string. */
Str0029F530* func_0029F530(Str0029F530* str, const char* s)
{
    Alloc0029F530 alloc;
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
/* merge_units: end func_0029F530 */

/* merge_units: begin func_0029F5B0 */
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
void func_0029F5B0(String* str, int arg) {
    int size;
    if (str->l.cap & 1) {
        size = str->l.size;
    } else {
        size = (unsigned char)str->s.size;
    }
    func_0013D710(str, size, 0, arg);
}
#pragma pop /* merge_units */
/* merge_units: end func_0029F5B0 */

/* merge_units: begin func_0029F5E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004AAD00[] = "basic_string: out_of_range"; }
extern "C" { char D_004AAD20[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_0029F5E0, D_004AAD00, D_004AAD20, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048BA18, D_0048BA20, Libc_Memmove, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_0029F5E0 */
