#include "types.h"
extern char D_004BA1B0[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004BA1B0. */
int func_0033F9D0(void)
{
    return strcmp(D_004BA1B0) == 0;
}
