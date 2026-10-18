/*
 * main/GenInfoObject: 2 files, 0043D620-0043D670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043D620 */
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

/* Replaces count characters at pos with the range [first, last). */
extern void* String_Replace(SsoString* str, int pos, int count, const char* first, const char* last, Allocator alloc);

/* Assigns the range [first, last) to the string (replaces the whole contents). */
void* func_0043D620(SsoString* str, const char* first, const char* last)
{
    Allocator alloc;
    int len;
    if (!(str->h.flags & 1))
        len = (unsigned char)str->h.s.shortLen;
    else
        len = str->longLen;
    return String_Replace(str, 0, len, first, last, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_0043D620 */

/* merge_units: begin func_0043D670 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004C00A0[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(func_0043D670, 0x80, D_004C00A0, GuiBitmapWidget_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_0043D670 */
