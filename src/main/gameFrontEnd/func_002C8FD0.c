#include "types.h"
extern int D_0048C2B0[];
int func_002C8FD0(int x)
{
 int i;
 for (i = 0; i < 5; i++) { if (x <= D_0048C2B0[i]) return i + 1; } return 5;
}
