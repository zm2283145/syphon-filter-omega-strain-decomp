#include "types.h"
typedef struct { char pad[0x184]; } R_AD00;
extern char D_0048BDBA[];
extern int func_002BC2A8(int a, int b, int c, int d);
int func_002BACB8(int a, int b, int c, int d)
{
    int s = *(unsigned short*)(D_0048BDBA + a * 0x184); return func_002BC2A8(a, b, c * s, s * d);
}