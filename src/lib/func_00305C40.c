#include "types.h"
extern unsigned char D_004912E8[];
extern int* D_004912F0[];
extern int D_004912F4[];
extern unsigned int D_0052980C[];
extern unsigned int D_00529808[];
int NetMsg_GetCallback(unsigned int a, unsigned int b, int* out)
{
    if (out == 0) return 2;
    *out = 0;
    if (D_004912E8[0] != 1) return 3;
    if (D_004912F0[0] == 0) return 3;
    if (D_004912F4[0] == 0) return 3;
    if (a >= D_0052980C[0]) return 2;
    if (b >= D_00529808[0]) return 2;
    *out = D_004912F0[0][a * D_00529808[0] + b];
    if (*out != 0) return 0;
    return 2;
}