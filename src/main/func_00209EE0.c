#include "types.h"
#pragma optimization_level 1
/* Returns the pointer to the smaller unsigned value. */
unsigned int* func_00209EE0(unsigned int* a, unsigned int* b) { return (*b < *a) ? b : a; }
#pragma optimization_level reset
