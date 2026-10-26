#include "types.h"
int sceIpuSync(int mode)
{
    int r = 0;
    switch (mode) {
    case 0:
        while ((int)*(volatile unsigned int*)0x10002010 < 0) { }
        r = 0;
        break;
    case 1:
        r = *(volatile unsigned int*)0x10002010 >> 31;
        break;
    }
    return r;
}