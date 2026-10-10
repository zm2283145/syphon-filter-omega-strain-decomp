#include "types.h"
extern char D_004BF680[];
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object D_004BF680. */
int func_00420E20(void)
{
    return strcmp(D_004BF680) == 0;
}
