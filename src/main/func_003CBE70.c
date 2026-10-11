#include "types.h"
typedef struct { unsigned int word; unsigned int len; char* data; } SBE70;
char* func_003CBE70(SBE70* s, int i)
{
    return ((s->word & 1) ? s->data : (char*)s + 1) + i;
}
