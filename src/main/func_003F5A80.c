#include "types.h"
typedef struct { char pad[0x48]; int m48; } T5A80;
extern int func_003F4A60(void* p);
extern int func_0010B388(T5A80* t);
unsigned char func_003F5A80(T5A80* t)
{
    unsigned char r = 0;
    if (!func_003F4A60(&t->m48)) {
        if (func_0010B388(t))
            r = 1;
    }
    return (unsigned char)(r & 0xFF);
}
