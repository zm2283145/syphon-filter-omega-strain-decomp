#include "types.h"
extern int Random_Next(void);
float func_002692D0(float max)
{
    return (float)(int)((float)(int)max * ((float)Random_Next() / 2147483648.0f));
}