#include "types.h"
typedef struct { unsigned int word; unsigned int len; char* data; } SBE70;
char* std_basic_string_char_char_traits_char_opIndex(SBE70* s, int i)
{
    return ((s->word & 1) ? s->data : (char*)s + 1) + i;
}
