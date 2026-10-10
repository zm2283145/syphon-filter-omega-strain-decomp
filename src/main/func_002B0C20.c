#include "types.h"
extern char D_004ABEA8[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004ABEA8. */
int func_002B0C20(void)
{
    return strcmp(D_004ABEA8) == 0;
}
