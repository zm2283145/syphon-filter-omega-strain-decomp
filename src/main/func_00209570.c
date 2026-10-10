#include "types.h"
extern int func_002071F0(void* s);
extern char* func_002071A0(void* s);
#pragma optimization_level 1
char* Str_CopyKey47(char* dst, void* s)
{
    int i;
    for (i = 0; i < 47; i++) {
        dst[i] = (i < func_002071F0(s)) ? func_002071A0(s)[i] : 0;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset
