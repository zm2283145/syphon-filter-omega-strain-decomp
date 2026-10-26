#include "types.h"
extern int D_0051ECE0;
extern int sceMc2ReadFile(int h, int a, int b, int c, int d);
/* Forwards to sceMc2ReadFile using the global handle D_0051ECE0. */
int my_read(int unused0, int unused1, int a, int b, int c, int d)
{
    return sceMc2ReadFile(D_0051ECE0, a, b, c, d);
}
