#include "types.h"
extern char D_004C1D00[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004C1D00. */
int func_00454120(void)
{
    return strcmp(D_004C1D00) == 0;
}
