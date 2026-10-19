#include "types.h"
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004ABB30[] = "basic_string: out_of_range"; }
extern "C" { char D_004ABB50[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_002AE130, D_004ABB30, D_004ABB50, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048BCC8, D_0048BCD0, Libc_Memmove, String_Assign)