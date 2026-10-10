#include "types.h"
extern void func_001AE280(char*, int);
#pragma optimization_level 1
char* MotionRegistry_MakeKey(char* dst, char* src)
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
        func_001AE280(dst, 2);
    }
    return dst;
}
#pragma optimization_level reset