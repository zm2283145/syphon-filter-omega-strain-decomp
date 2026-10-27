/*
 * main/gameFrontEnd: 2 files, 002CE6F0-002CE740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CE6F0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; } SsoString;

extern void std_basic_string_char_char_traits_char_do_replace(SsoString* self, int pos, int n, const char* first, const char* last, Alloc alloc);

/* Assigns [first, last) to the string by replacing its whole contents. */
void func_002CE6F0(SsoString* self, const char* first, const char* last)
{
    Alloc alloc;
    std_basic_string_char_char_traits_char_do_replace(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, first, last, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_002CE6F0 */

/* merge_units: begin func_002CE740 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Clears the word at +4 (the count when used as a PtrVec). */
void func_002CE740(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002CE740 */
