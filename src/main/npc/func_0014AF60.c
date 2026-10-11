#include "types.h"
typedef struct { int pad[2]; void** items; } Reg_0014AF60;
typedef struct { char pad[0x50]; int id; } Ai_0014AF60;
typedef struct { char pad[0x1B0]; Ai_0014AF60* ai; } NPC_0014AF60;
extern Reg_0014AF60* D_004FFBE0;
void* cNPC_v62(NPC_0014AF60* self)
{
    int id = self->ai->id;
    void* r = 0;
    if (id >= 0)
        r = D_004FFBE0->items[id];
    return r;
}