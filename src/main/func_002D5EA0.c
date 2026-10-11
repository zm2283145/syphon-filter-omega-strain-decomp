#include "types.h"
typedef struct { char pad[0x30]; short h30; } T2D5EA0;
typedef struct { char pad[0x3584]; T2D5EA0* p3584; } W2D5EA0;
typedef struct { char pad[0x30]; W2D5EA0* x30; } S2D5EA0;
int func_002D5EA0(S2D5EA0* s)
{
    if (s->x30)
        return s->x30->p3584 ? s->x30->p3584->h30 : 4;
    return 4;
}