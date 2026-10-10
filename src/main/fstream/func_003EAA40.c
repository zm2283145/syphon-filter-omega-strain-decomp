#include "types.h"

typedef struct { char pad[0x94]; unsigned char flag; } Obj94;

/* Returns 1 if the byte flag at +0x94 of the second argument is set. */
unsigned char func_003EAA40(void* self, Obj94* obj)
{
    unsigned char result = 0;
    if (obj->flag)
        result = 1;
    return result;
}
