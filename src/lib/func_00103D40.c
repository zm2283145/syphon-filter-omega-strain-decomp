#include "types.h"
const unsigned int D_00485EE0[10] = { 0x10008000, 0x10009000, 0x1000A000, 0x1000B000, 0x1000B400, 0x1000C000, 0x1000C400, 0x1000C800, 0x1000D000, 0x1000D400 };

int func_00103D40(unsigned int arg0)
{
    if (arg0 < 10) {
        return ((int*)D_00485EE0)[arg0];
    }
    return 0;
}
