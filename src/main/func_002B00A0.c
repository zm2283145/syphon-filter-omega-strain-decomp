#include "types.h"
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004ABD20[] = "basic_string: out_of_range"; }
extern "C" { char D_004ABD40[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_002B00A0, D_004ABD20, D_004ABD40, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048BD00, D_0048BD08, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP)