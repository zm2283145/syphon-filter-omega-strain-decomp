/*
 * main/GuiGameOptions: 4 files, 00298690-002987A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00298690 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* cString_ctor_void(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00298690 */

/* merge_units: begin func_002986B0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } V4_r8;
static inline void Set(V4_r8* o, float x, float y, float z, float w) { o->x = x; o->y = y; o->z = z; o->w = w; }
void InterpolateColor_tRGBAR_tRGBAR_float(V4_r8* out, V4_r8* a, V4_r8* b, float t)
{
    Set(out, a->x + t * (b->x - a->x), a->y + t * (b->y - a->y), a->z + t * (b->z - a->z), a->w + t * (b->w - a->w));
}
#pragma pop /* merge_units */
/* merge_units: end func_002986B0 */

/* merge_units: begin func_00298720 */
#pragma push /* merge_units */
/* String object: three words, zeroed before construction. */
typedef struct StrObj {
    int w0;
    int w1;
    int w2;
} StrObj;

extern int strlen(const char* s); /* strlen */
extern void std_basic_string_char_char_traits_char_reserve(StrObj* str, int capacity);
extern void std_basic_string_char_char_traits_char_do_replace(StrObj* str, int pos, int count, const char* first, const char* last, char alloc);

/* String constructor from a C string. */
StrObj* func_00298720(StrObj* self, const char* cstr) {
    volatile char alloc[4];
    int len;
    self->w0 = 0;
    self->w1 = 0;
    self->w2 = 0;
    len = strlen(cstr);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, cstr, cstr + len, alloc[0]);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00298720 */

/* merge_units: begin func_002987A0 */
#pragma push /* merge_units */
typedef struct { unsigned long long isLong : 1; unsigned long long size : 7; } Short002987A0;
typedef union { unsigned int flags; Short002987A0 s; struct { int f0; int length; char* data; } l; } Str002987A0;
extern void std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(Str002987A0* str, int pos, int count, const char* s, int n);
/* Replace the whole string with the C string s. */
void func_002987A0(Str002987A0* str, const char* s)
{
    std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(str, 0, (str->flags & 1) ? str->l.length : (unsigned char)str->s.size, s, strlen(s));
}
#pragma pop /* merge_units */
/* merge_units: end func_002987A0 */
