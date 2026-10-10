#include "types.h"
extern void Global_PlayXA(int a, int b);
/* Script: PlayXA(a, b). */
int Script_PlayXA_2(int* args)
{
    volatile int b = args[1]; /* staged through the stack */
    volatile int a = args[0];
    Global_PlayXA(a, b);
    return 0;
}
