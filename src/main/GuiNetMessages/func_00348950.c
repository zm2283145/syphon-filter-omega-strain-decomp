#include "types.h"
typedef struct { char pad[0x94]; int a94; int a98; int a9C; } S348950;
int func_00348950(S348950* o, int k)
{
    switch (k) {
    case 9:
        return o->a98;
    case 0:
    case 1:
        return o->a9C;
    default:
        return o->a94;
    }
}
