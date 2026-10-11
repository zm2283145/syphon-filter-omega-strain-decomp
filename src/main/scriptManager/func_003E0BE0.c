#include "types.h"
typedef struct { char pad[0x3C]; unsigned char m3C; } T0BE0;
extern T0BE0* func_003E0C30(int a);
T0BE0* func_003E0BE0(int a)
{
    T0BE0* p = func_003E0C30(a);
    if (p && p->m3C)
        return p;
    return 0;
}
