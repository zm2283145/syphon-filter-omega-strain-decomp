#include "types.h"
typedef struct { int pad[2]; void** items; } Reg_01E0;
typedef struct { char pad[0x4C]; int a; int pad50; int b; } S_01E0;
extern Reg_01E0* D_004FFBE0;
void* func_001601E0(S_01E0* self)
{
    int id = self->a;
    void* r = 0;
    id = id >= 0 ? id : self->b;
    if (id >= 0)
        r = D_004FFBE0->items[id];
    return r;
}