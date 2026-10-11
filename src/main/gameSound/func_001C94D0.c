#include "types.h"
extern int func_003A81A0(int);
int func_001C94D0(void* self, unsigned char kind)
{
    int r = 0;
    switch (kind) {
    case 0: r = func_003A81A0(0); break;
    case 1: r = func_003A81A0(1); break;
    case 2: r = func_003A81A0(2); break;
    }
    return r;
}