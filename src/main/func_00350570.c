#include "types.h"
extern char D_004BAD60[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004BAD60. */
int func_00350570(void)
{
    return strcmp(D_004BAD60) == 0;
}
