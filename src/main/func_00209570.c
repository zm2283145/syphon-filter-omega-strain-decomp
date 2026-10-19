#include "types.h"
extern int String_Length(void* s);
extern char* String_CStr_Thunk(void* s);
#pragma optimization_level 1
char* Str_CopyKey47(char* dst, void* s)
{
    int i;
    for (i = 0; i < 47; i++) {
        dst[i] = (i < String_Length(s)) ? String_CStr_Thunk(s)[i] : 0;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset
