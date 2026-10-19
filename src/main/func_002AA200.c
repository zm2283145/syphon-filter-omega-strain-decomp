#include "types.h"
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004AB830[] = "basic_string: out_of_range"; }
extern "C" { char D_004AB850[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_002AA200, D_004AB830, D_004AB850, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048BC18, D_0048BC20, Libc_Memmove, String_Assign)