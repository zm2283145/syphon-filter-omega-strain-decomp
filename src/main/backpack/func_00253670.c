#include "types.h"

extern float D_004F7E70, D_004F7E74, D_004F7E78, D_004F7E7C;
extern unsigned char D_004F7E80;

/* Sets the pickup text colour from 0-255 RGB and a float alpha, and marks it overridden. */
void Global_SetPickupTextColor(int r, int g, int b, float a)
{
    D_004F7E70 = r / 255.0f;
    D_004F7E74 = g / 255.0f;
    D_004F7E78 = b / 255.0f;
    D_004F7E7C = a;
    D_004F7E80 = 1;
}
