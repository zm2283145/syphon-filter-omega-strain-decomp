#include "types.h"
typedef struct { int w[3]; } E12;
#pragma optimization_level 1
int std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP_randomaccessiteratortag(E12* a, E12* b)
{
    return b - a;
}
#pragma optimization_level reset