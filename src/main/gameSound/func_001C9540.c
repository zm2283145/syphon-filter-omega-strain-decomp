#include "types.h"
extern void func_003A81D0(int, int);
void func_001C9540(void* self, unsigned char kind, int v)
{
    switch (kind) {
    case 0: func_003A81D0(0, v); func_003A81D0(3, v); break;
    case 1: func_003A81D0(1, v); break;
    case 2: func_003A81D0(2, v); func_003A81D0(14, v); break;
    }
}