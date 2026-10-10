#include "types.h"

extern float D_004F7D60, D_004F7D64, D_004F7D68, D_004F7D6C;

/* Sets the interface text colour from 0-255 RGB and a float alpha. */
void Global_SetInterfaceTextColor(int r, int g, int b, float a)
{
    D_004F7D6C = a;
    D_004F7D60 = r / 255.0f;
    D_004F7D64 = g / 255.0f;
    D_004F7D68 = b / 255.0f;
}
