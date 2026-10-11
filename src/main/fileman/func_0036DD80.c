#include "types.h"
typedef struct { unsigned int flags; char pad[0x94]; char* a98; } S36DD80;
char* func_0036DD80(S36DD80* o)
{
    if (o->flags & 2) return o->a98 + 0x80;
    if (o->flags & 1) return o->a98;
    return 0;
}