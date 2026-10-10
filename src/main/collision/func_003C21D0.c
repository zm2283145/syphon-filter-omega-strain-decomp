#include "types.h"
char* func_003C21D0(char* p)
{
    volatile char* q;
    *p = 0;
    q = p + 1;
    do {
        *q = 0;
        q++;
    } while (q != p + 4);
    return p;
}