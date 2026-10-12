#include "types.h"
extern int Random_Next(void);
float Script_RandomIntCore(float max)
{
    return (float)(int)((float)(int)max * ((float)Random_Next() / 2147483648.0f));
}