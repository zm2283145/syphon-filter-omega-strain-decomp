#include "types.h"

extern int Random_Next(void);

/* Returns a random float in [lo, hi). */
float Global_Random_2(float lo, float hi) {
    float t = (float)Random_Next() / 2147483648.0f;
    float range = hi - lo;
    return lo + range * t;
}
