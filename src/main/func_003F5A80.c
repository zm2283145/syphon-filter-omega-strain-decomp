#include "types.h"
typedef struct { char pad[0x48]; int m48; } T5A80;
extern int viBufCount(void* p);
extern int sceMpegIsRefBuffEmpty(T5A80* t);
unsigned char videoDecIsFlushed(T5A80* t)
{
    unsigned char r = 0;
    if (!viBufCount(&t->m48)) {
        if (sceMpegIsRefBuffEmpty(t))
            r = 1;
    }
    return (unsigned char)(r & 0xFF);
}
