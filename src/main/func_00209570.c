#include "types.h"
extern int cString_Length(void* s);
extern char* cString_opCast_constcharPtr(void* s);
#pragma optimization_level 1
char* cString16N_3_ctor_cStringR(char* dst, void* s)
{
    int i;
    for (i = 0; i < 47; i++) {
        dst[i] = (i < cString_Length(s)) ? cString_opCast_constcharPtr(s)[i] : 0;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset
