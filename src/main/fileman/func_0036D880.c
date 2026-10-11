#include "types.h"
typedef struct { char pad[0x14C]; unsigned char a14C; } C36D880;
typedef struct { unsigned int flags; char pad[0x94]; C36D880* a98; } S36D880;
int func_0036D880(S36D880* o)
{
    if (o->flags & 2) {
        if (o->a98->a14C == 2) return 1;
    } else if (o->flags & 1) {
        return 1;
    }
    return 0;
}