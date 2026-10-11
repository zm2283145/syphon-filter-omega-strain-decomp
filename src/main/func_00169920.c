#include "types.h"
typedef struct { char pad[0x250]; unsigned char state; } S_9920;
extern S_9920* func_001698C0(void);
unsigned char func_00169920(void)
{
    unsigned char s = func_001698C0()->state;
    unsigned char r = 1;
    if (s != 0 && s != 4)
        r = 0;
    return r;
}