#include "types.h"
typedef struct { char pad[0x250]; unsigned char state; } S_9920;
extern S_9920* App_GetInstance(void);
unsigned char func_00169920(void)
{
    unsigned char s = App_GetInstance()->state;
    unsigned char r = 1;
    if (s != 0 && s != 4)
        r = 0;
    return r;
}