#include "types.h"
extern char D_00582590[];
extern char D_00582594[];
extern char D_00582598[];
extern char D_0058259C[];
extern char D_005825A0[];
extern char D_005825A4[];
void StaticInit_nellymoser_wrapper(void)
{
    *(int*)D_00582594 = 0;
    *(int*)D_0058259C = 0;
    *(int*)D_00582590 = -1;
    *(int*)D_00582598 = -1;
    *(int*)D_005825A0 = -1;
    *(int*)D_005825A4 = 0;
}
