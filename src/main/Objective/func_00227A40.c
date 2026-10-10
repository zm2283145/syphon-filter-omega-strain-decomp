#include "types.h"

typedef struct { float r, g, b, a; } ColorF;

/* Converts 0-255 integer RGB to floats in [0,1] and sets alpha. */
void func_00227A40(ColorF* out, int r, int g, int b, float a)
{
    out->r = r / 255.0f;
    out->g = g / 255.0f;
    out->b = b / 255.0f;
    out->a = a;
}
