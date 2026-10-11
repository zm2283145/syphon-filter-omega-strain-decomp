#include "types.h"
typedef struct { char c[21]; } S445;
typedef struct { S445 name; int x; } N445;
extern char *D_00585E60;
void func_00445F40(int d0, int d1, int d2, N445 *src) {
    N445 *d;
    *(int *)(D_00585E60 + 0x188) = 1;
    d = (N445 *)(D_00585E60 + 0x334);
    d->name = src->name;
    d->x = src->x;
}
