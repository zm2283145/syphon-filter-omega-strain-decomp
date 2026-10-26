#include "types.h"
typedef struct { char d[36]; } E;
#pragma optimization_level 1
/* Returns the number of 36-byte elements between a and b. */
int std_distance_cSkaTransBLENDP_cSkaTransBLENDP_randomaccessiteratortag(E* a, E* b) { return b - a; }
#pragma optimization_level reset
