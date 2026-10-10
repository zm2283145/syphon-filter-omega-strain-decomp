#include "types.h"
extern int func_00115090(int a, int b, int c, void* sp, int e);
/* Calls func_00115090 with a stack scratch buffer and a zero flag. */
int func_001152B8(int a, int b, int c)
{
    int buf[4];
    return func_00115090(a, b, c, buf, 0);
}
