#include "types.h"
extern int cString_Length(void* s);
extern char* cString_opCast_constcharPtr(void* s);
#pragma optimization_level 1
char* cString16N_2_ctor_cStringR(char* dst, void* s)
{
    int i;
    for (i = 0; i < 31; i++) {
        char c;
        if (i < cString_Length(s))
            c = cString_opCast_constcharPtr(s)[i];
        else
            c = 0;
        dst[i] = c;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset