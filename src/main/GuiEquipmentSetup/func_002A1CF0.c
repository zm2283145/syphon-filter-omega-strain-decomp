#include "types.h"
extern char D_004AB480[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004AB480. */
int func_002A1CF0(void)
{
    return strcmp(D_004AB480) == 0;
}
