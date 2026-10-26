#include "types.h"
extern int Newlib_FindenvR(int a, int b, void* sp);
/* Calls Newlib_FindenvR with a stack scratch buffer. */
int Newlib_GetenvR(int a, int b)
{
    int buf[4];
    return Newlib_FindenvR(a, b, buf);
}
