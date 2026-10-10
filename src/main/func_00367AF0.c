#include "types.h"
extern char D_004BBDC0[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004BBDC0. */
int func_00367AF0(void)
{
    return strcmp(D_004BBDC0) == 0;
}
