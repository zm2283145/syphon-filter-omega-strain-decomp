#include "types.h"
extern void func_00369EE0(void*, int);
typedef struct { char d[0x1C0]; } G6E36A;
typedef struct { int a; int n; char pad[0x38]; G6E36A e[2]; int cur; } G6C36A;
void func_0036A240(G6C36A* p)
{
    int i;
    for (i = 0; i < p->n; i++)
        func_00369EE0(&p->e[i], p->cur);
    p->cur = -1;
}