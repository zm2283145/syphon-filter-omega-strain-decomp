#include "types.h"
typedef union { int i; unsigned char uc; signed char sc; } Arg00267620;
extern unsigned char Global_AddMaterialProperties(int a, unsigned char b, int c, signed char d, int e, int f, int g, float h);
/* Script: AddMaterialProperties(...). */
int Script_AddMaterialProperties(Arg00267620* args)
{
    int f[1]; /* staged through the stack */
    int e[1];
    signed char d;
    int c[1];
    unsigned char b;
    int a[1];
    f[0] = args[5].i;
    e[0] = args[4].i;
    d = args[3].sc;
    c[0] = args[2].i;
    b = args[1].uc;
    a[0] = args[0].i;
    return Global_AddMaterialProperties(*(int*)a, b, *(int*)c, d, *(int*)e, *(int*)f, 0, 0.2f);
}
