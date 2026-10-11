#include "types.h"
typedef struct { char pad0[0x50]; unsigned char* p; } O_45CF80;
unsigned char func_0045CF80(O_45CF80* o)
{
    unsigned char r = 0;
    if (o->p != 0 && (*(unsigned short*)(o->p + 0x14) & 2) != 0) r = 1;
    return r;
}