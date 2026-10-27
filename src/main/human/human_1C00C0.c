/*
 * main/human: 4 files, 001C00C0-001C0180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C00C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_tree_pair_cString_value_compare_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C00C0 */

/* merge_units: begin func_001C00D0 */
#pragma push /* merge_units */
typedef struct { int w[3]; } String;
extern void std_basic_string_char_char_traits_char_ctor_basicstringR(String* dst, String* src);
extern void std_basic_string_char_char_traits_char_append_charP(String* s, int arg);
extern void String_Dtor(String* s, int flags);
/* Copies src, transforms the copy with arg, and assigns it to dst. */
int opAdd_cStringR_charP(String* dst, String* src, int arg)
{
    String tmp;
    std_basic_string_char_char_traits_char_ctor_basicstringR(&tmp, src);
    std_basic_string_char_char_traits_char_append_charP(&tmp, arg);
    std_basic_string_char_char_traits_char_ctor_basicstringR(dst, &tmp);
    String_Dtor(&tmp, 0);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C00D0 */

/* merge_units: begin func_001C0130 */
#pragma push /* merge_units */
extern char D_0049EE30[]; /* format string */
extern char D_0048B2F8[];
extern int sprintf(char* buf, const char* fmt, ...); /* sprintf */
extern void cHogList_Close(void* target, const char* text);

/* Formats D_0048B2F8 into a local buffer and passes it to cHogList_Close. */
void cLoader_CloseHogWithLevelSpecificAnimations(void* self, void* target)
{
    char buf[0x80];
    sprintf(buf, D_0049EE30, D_0048B2F8);
    cHogList_Close(target, buf);
}
#pragma pop /* merge_units */
/* merge_units: end func_001C0130 */

/* merge_units: begin func_001C0180 */
#pragma push /* merge_units */
extern void cHogList_Open(void* target, char* text, int a, int b);

/* Formats D_0048B2F8 with the D_0049EE30 format and passes the text to cHogList_Open. */
void cLoader_OpenHogWithLevelSpecificAnimations_ForAccessByInitScript(void* self, void* target)
{
    char buf[0x80];
    sprintf(buf, D_0049EE30, D_0048B2F8);
    cHogList_Open(target, buf, 1, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_001C0180 */
