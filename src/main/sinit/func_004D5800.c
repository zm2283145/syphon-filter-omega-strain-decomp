#include "types.h"
extern char D_00542D10[];
extern void cVU0Man_ctor();
void StaticInit_vu0man(void)
{
    cVU0Man_ctor((int)D_00542D10);
}
