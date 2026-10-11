#include "types.h"
typedef struct { int pad[2]; void** items; } Reg_0014AF30;
typedef struct { char pad[0x58]; int id; } Ai_0014AF30;
typedef struct { char pad[0x1B0]; Ai_0014AF30* ai; } NPC_0014AF30;
extern Reg_0014AF30* D_004FFBE0;
void* cNPC_v63(NPC_0014AF30* self)
{
    int id = self->ai->id;
    void* r = 0;
    if (id >= 0)
        r = D_004FFBE0->items[id];
    return r;
}