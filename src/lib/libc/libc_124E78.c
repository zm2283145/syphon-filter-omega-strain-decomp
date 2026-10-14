#include "types.h"
extern int func_00124D30(int a, int b, void* sp);
/* Calls func_00124D30 with a stack scratch buffer. */
int func_00124E78(int a, int b)
{
    int buf[4];
    return func_00124D30(a, b, buf);
}
