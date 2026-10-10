#include "types.h"

extern unsigned char D_00572410;
extern unsigned char D_005721D8;
extern char D_005721E0[16];
extern char D_004BF9D0[];
extern int snprintf(char* buf, int size, const char* fmt, ...); /* snprintf-like */

/* Sets two flags and formats the default string into a 16-byte buffer. */
void func_00429A60(void)
{
    D_00572410 = 1;
    D_005721D8 = 1;
    snprintf(D_005721E0, 16, D_004BF9D0);
}
