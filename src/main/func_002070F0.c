#include "types.h"
extern int String_Length(void* s);
extern char* func_002071A0(void* s);
#pragma optimization_level 1
char* func_002070F0(char* dst, void* s)
{
    int i;
    for (i = 0; i < 31; i++) {
        char c;
        if (i < String_Length(s))
            c = func_002071A0(s)[i];
        else
            c = 0;
        dst[i] = c;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset