#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

typedef struct PackedWord {
    unsigned int flag : 1;
    unsigned int value : 31;
} PackedWord;

extern PackedWord* details_compressed_pair_imp_rep_s_2_first_void(void* obj);

/* Returns the 31-bit value field of details_compressed_pair_imp_rep_s_2_first_void's result. */
unsigned int std_basic_string_char_char_traits_char_long_cap(void* obj) {
    return details_compressed_pair_imp_rep_s_2_first_void(obj)->value;
}

#pragma pop
