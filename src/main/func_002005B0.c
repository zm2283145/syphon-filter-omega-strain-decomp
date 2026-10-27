#include "types.h"
extern void MEMCLEAR16(char*, int);
#pragma optimization_level 1
char* cString16N_2_ctor_charP(char* dst, char* src)
{
    if (src != 0) {
        unsigned char done = 0;
        int i;
        for (i = 0; i < 31; i++) {
            if (src[i] == 0) {
                done = 1;
            }
            dst[i] = done ? 0 : src[i];
        }
        dst[i] = 0;
    } else {
        MEMCLEAR16(dst, 2);
    }
    return dst;
}
#pragma optimization_level reset