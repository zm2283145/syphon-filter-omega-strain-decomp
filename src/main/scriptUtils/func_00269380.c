#include "types.h"
extern int Random_Next(void);
/* Returns a random float in [0, range). */
float Global_Random(float range) { return range * ((float)Random_Next() / 2147483648.0f); }
