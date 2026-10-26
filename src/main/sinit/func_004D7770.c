#include "types.h"
extern char D_00583878[];
extern char D_0058387C[];
void StaticInit_camera(void)
{
    *(int*)D_00583878 = 0;
    *(int*)D_0058387C = -2;
}
