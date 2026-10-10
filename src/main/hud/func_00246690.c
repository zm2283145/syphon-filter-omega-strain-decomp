#include "types.h"

extern float D_004F7D70;
extern float D_004F7D74;
extern float D_004F7D78;
extern float D_004F7D7C;

/* Sets the night-vision interface text color from 0..255 components and an alpha. */
void Global_SetNVInterfaceTextColor(int r, int g, int b, float a)
{
    D_004F7D7C = a;
    D_004F7D70 = (float)r / 255.0f;
    D_004F7D74 = (float)g / 255.0f;
    D_004F7D78 = (float)b / 255.0f;
}
