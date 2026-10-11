#include "types.h"
typedef struct { char pad[0x50004]; int count; } T76C0;
int func_003F76C0(T76C0* t, int n)
{
    int k = t->count < n ? t->count : n;
    t->count -= k;
    return k;
}
