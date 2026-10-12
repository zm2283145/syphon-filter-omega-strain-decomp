#include "types.h"
typedef struct { char pad[0x4C]; int id; } Ai_F3F0;
typedef struct { char pad[0x78]; int x78; } Obj_F3F0;
typedef struct { char pad[0x1B0]; Ai_F3F0* ai; } NPC_F3F0;
extern Obj_F3F0* NpcPath_FirstLinkOfType(int id, int kind);
extern int func_0015FE80(Ai_F3F0* ai, int v);
int cNPC_v1F(NPC_F3F0* self, int r)
{
    int id = self->ai->id;
    if (id >= 0) {
        Obj_F3F0* o = NpcPath_FirstLinkOfType(id, 7);
        if (o && func_0015FE80(self->ai, o->x78))
            r = 2;
    }
    return r;
}