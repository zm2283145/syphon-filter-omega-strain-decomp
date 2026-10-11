#include "types.h"
typedef struct { int w[3]; } E12;
#pragma optimization_level 1
int func_002099F0(E12* a, E12* b)
{
    return b - a;
}
#pragma optimization_level reset