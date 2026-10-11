#include "types.h"
typedef struct { char pad[0x98]; int m98; unsigned short m9C; } T1610;
unsigned char func_003D1610(T1610* p)
{
    unsigned char r = 0;
    if (p->m98) {
        unsigned short f = p->m9C;
        if (f & 0x8000) {
            r = 0;
        } else if (f & 0x4000) {
            r = f & ~0x4000;
        } else {
            r = f;
        }
    }
    return r;
}
