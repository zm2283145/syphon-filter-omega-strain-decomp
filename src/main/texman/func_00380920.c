#include "types.h"
typedef struct { char pad[0x38]; int stride; int pad2; } TdxHdr_e1;
char* Tdx_GetFrame(TdxHdr_e1* t, unsigned int n)
{
    char* p = (char*)t + 0x40;
    unsigned int i;
    for (i = 0; i < n; i++) {
        p += t->stride;
    }
    return p;
}