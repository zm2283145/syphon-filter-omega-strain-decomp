#include "types.h"
typedef struct { int f; char p[0x7C]; } C1E_3D43;
typedef struct { char pad[0x534]; C1E_3D43 e[511]; char pad2[0x24]; int count; } C1S_3D43;
void func_003D4300(C1S_3D43* s)
{
    int i;
    for (i = 0; i < s->count; i++)
        s->e[i].f = 0;
    s->count = 0;
}