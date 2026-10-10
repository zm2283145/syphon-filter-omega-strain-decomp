#include "types.h"
extern int D_00583888;
extern unsigned char D_005838A0[];
/* Mark slot `index` as set while the feature flag is enabled. */
void func_0043ACB0(int unused, int index)
{
    if (D_00583888) {
        D_005838A0[index] = 1;
    }
}
