#include "types.h"
typedef struct { unsigned int w0; int w4; char* ptr; } Str_1BFF20;
void func_001BFF20(char** out, Str_1BFF20* s)
{
    *out = (s->w0 & 1) ? s->ptr : (char*)s + 1;
}