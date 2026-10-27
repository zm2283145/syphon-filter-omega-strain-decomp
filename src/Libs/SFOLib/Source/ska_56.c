/*
 * Libs/SFOLib/Source/ska: 1 file, 003B52B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B52B0 */
#pragma push /* merge_units */
#include "types.h"

extern void std_basic_string_char_char_traits_char_substr(void* tmp);
extern void std_basic_string_char_char_traits_char_ctor_basicstringR(void* self, void* tmp);
extern void String_Dtor(void* tmp, int flag);

/* Builds a temporary object, applies it to self, then destroys it; returns 0. */
int cString_Substr(void* self) {
    char tmp[16];
    std_basic_string_char_char_traits_char_substr(tmp);
    std_basic_string_char_char_traits_char_ctor_basicstringR(self, tmp);
    String_Dtor(tmp, -1);
    return 0;
}
static inline void merge_flush_func_003B52B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B52B0 */
