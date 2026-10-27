#include "types.h"
extern void XLib_DrawLensFlares(void* a, void* b, void* c, int* d, int* zero, float* one, int flag, int e, int f);
/* Calls XLib_DrawLensFlares with default zero / 1.0 parameters and the flag set. */
void XLib_DrawLensFlare(void* a, void* b, void* c, int d, int e, int f)
{
    int dv = d;
    float one = 1.0f;
    int zero = 0;
    XLib_DrawLensFlares(a, b, c, &dv, &zero, &one, 1, e, f);
}
