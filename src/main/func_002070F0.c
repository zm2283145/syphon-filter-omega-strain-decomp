#include "types.h"
extern int String_Length(void* s);
extern char* String_CStr_Thunk(void* s);
#pragma optimization_level 1
char* func_002070F0(char* dst, void* s)
{
    int i;
    for (i = 0; i < 31; i++) {
        char c;
        if (i < String_Length(s))
            c = String_CStr_Thunk(s)[i];
        else
            c = 0;
        dst[i] = c;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset