#include "types.h"
typedef struct { char pad[0x184]; } R_AD00;
extern char D_0048BDBA[];
extern int _sceMcCoreWritePage(int a, int b, int c, int d);
int func_002BAD00(int a, int b, int c, int d)
{
    int s = *(unsigned short*)(D_0048BDBA + a * 0x184); return _sceMcCoreWritePage(a, b, c * s, s * d);
}