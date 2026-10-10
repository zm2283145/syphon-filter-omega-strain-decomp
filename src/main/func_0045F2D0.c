#include "types.h"
extern char D_004C25A8[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004C25A8. */
int func_0045F2D0(void)
{
    return strcmp(D_004C25A8) == 0;
}
