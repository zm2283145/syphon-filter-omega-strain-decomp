/*
 * main/Loader: range (3 files, 001C4300-001C43A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

/* merge_units: begin func_001C4300 */
#pragma push /* merge_units */
typedef struct { int w0, w4, w8; } String;
String* func_001C4330(String* str, int pos, int count, const char* s); /* gsynth: defined below */
/* Short/long string header: bit 0 = long form, bits 1-7 = inline length. */
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;

#if 0 /* merge_units */
extern void func_001C4330(StrHdr* str, int len, int start, int arg);
#endif /* merge_units */
#define func_001C4330(a0, a1, a2, a3) ((void)func_001C4330((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */


/* Forwards to func_001C4330 with the string's current length and start 0. */
void func_001C4300(StrHdr* str, int arg) {
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    func_001C4330(str, len, 0, arg);
}
#undef func_001C4330 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C4300 */

/* merge_units: begin func_001C4330 */
#pragma push /* merge_units */
typedef struct { char unused; } Alloc; /* empty allocator object passed by value */

extern String* String_Replace(String* str, int pos, int count, const char* first, const char* last, Alloc alloc);
/* Replaces count characters at pos with the C string s. */
String* func_001C4330(String* str, int pos, int count, const char* s)
{
    Alloc alloc;
    return String_Replace(str, pos, count, s, s + strlen(s), alloc);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C4330 */

/* merge_units: begin func_001C43A0 */
#pragma push /* merge_units */
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; char* longData; } SsoString;

extern int String_Compare(SsoString* self, int pos, int n, const char* s, int len);

/* Compare the entire string with a C string; retain the legacy symbol name. */
int String_AssignCStr_1C43A0(SsoString* self, const char* s)
{
    int len = strlen(s);
    return String_Compare(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, s, len);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C43A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C43A0 */
