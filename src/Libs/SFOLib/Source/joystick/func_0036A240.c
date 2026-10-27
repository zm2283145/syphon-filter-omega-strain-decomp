#include "types.h"
extern void cJoyPad_Clear(void*, int);
typedef struct { char d[0x1C0]; } G6E36A;
typedef struct { int a; int n; char pad[0x38]; G6E36A e[2]; int cur; } G6C36A;
void cJoystick_Debounce(G6C36A* p)
{
    int i;
    for (i = 0; i < p->n; i++)
        cJoyPad_Clear(&p->e[i], p->cur);
    p->cur = -1;
}