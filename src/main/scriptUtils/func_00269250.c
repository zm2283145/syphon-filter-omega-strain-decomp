#include "types.h"
extern int Random_Next(void);
float Global_RandomInt(float lo, float hi)
{
    float r = (float)Random_Next() / 2147483648.0f;
    float d = (float)((int)hi - (int)lo);
    return (float)(int)((float)(int)lo + d * r);
}
