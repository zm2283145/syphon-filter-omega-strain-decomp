#include "types.h"
extern char D_004A9E40[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004A9E40. */
int func_002927F0(void)
{
    return strcmp(D_004A9E40) == 0;
}
