/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* details_compressed_pair_imp_rep_s_2_first_void(Word*);
extern void std_basic_string_char_char_traits_char_length(void);

/* Tests bit 0 of the word. */
int std_basic_string_char_char_traits_char_is_long(Word* self) {
    return (details_compressed_pair_imp_rep_s_2_first_void(self)->value & 1) != 0;
}

void String_Length(void) {
    std_basic_string_char_char_traits_char_length();
}
